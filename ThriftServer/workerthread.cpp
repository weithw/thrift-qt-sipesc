#include "workerthread.h"

#include "time.h"

WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{

    b_running = false;
    this->mTask = NULL;

    connect(this,SIGNAL(newTaskAssigned(qint32)),this,SLOT(onNewTaskAssigned()),Qt::QueuedConnection);
}


WorkerThread::~WorkerThread(){

    reset();
    quit();
    wait(1000);
}

//线程是否空闲
bool WorkerThread::isAvaiable(){
  return !b_running;
}
//给线程分配新任务
bool WorkerThread::assignTask(Task * task){
    if(task == NULL ){
        qDebug() << tr("The task is NULL !! In run worker thread:") << QThread::currentThreadId();
        return false;
    }
    else if(task->taskId <= 0){
        qDebug() << tr(" The task has no Id !! In run worker thread:") << QThread::currentThreadId();
        return false;
    }
    else if( mTask != NULL || b_running){

        qDebug() << tr("Can not assign task to a thread which is busy !! In run worker thread:") << QThread::currentThreadId();
        return false;
    }

    mTask = task;


    emit newTaskAssigned(mTask->taskId);

    return true;
}

void WorkerThread::run(){

    qDebug() << tr("Start worker thread:") << QThread::currentThreadId()<<"\n";

    if(b_running){

        qDebug() << tr("Error: Already running, worker thread:") << QThread::currentThreadId()<<"\n";
        return;
    }

    if(mTask != NULL){
         emit newTaskAssigned(mTask->taskId);
    }

    exec();
}

void WorkerThread::reset(){
    mTask = NULL;
    b_running = false;
}

void WorkerThread::stop(){

    if(mTask == NULL || !b_running){

       qDebug() << tr("Error: call stop on a not working thread:")<<QThread::currentThreadId();
       return;
    }

    mTask->status = TaskStatus::CANCELED;

    time_t now;
    time(&now);
    mTask->stopedTime = now;   

    reset();
    quit();
}

void WorkerThread:: onNewTaskAssigned(){
    qDebug() << tr("Receive Task In run worker thread:") << QThread::currentThreadId();
    if(mTask == NULL || b_running){
        return;
    }

    b_running = true;

    time_t now;
    time(&now);
    mTask->startedTime = now;

    try{
         taskPaser.parse(mTask);

    }catch( SipescException ex){
         qDebug() << tr("Excectption when execute task...") << QThread::currentThreadId()<<"\n";
    }

    time(&now);

    mTask->stopedTime = now;

    int32_t taskId = mTask->taskId;

    reset();

    if(onWorkListener != NULL){
        onWorkListener->onTaskDone(taskId);
    }

}

void WorkerThread:: setWorkListener(TaskListener* listener){
    this->onWorkListener = listener;
}
