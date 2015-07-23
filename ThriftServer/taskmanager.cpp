#include "taskmanager.h"
#include "usermanager.h"
#include "time.h"
#include <sstream>
TaskManager::TaskManager(QObject *parent) :
    QObject(parent),mWorkThreadPool(20)
{
    qDebug()<<"task manager in thread:"<<QThread::currentThreadId();
    nextTaskId = 1; //最好从数据库中读取
    tasks.clear();

}

TaskManager::~TaskManager(){

    QList<Task *> allTasks = tasks.values();
    qDeleteAll(allTasks);
}

vector<Task> TaskManager::listUserTasks(const std::string& token) {
    User user = UserManagerHelper::getUserManager()->getUserByToken(token);
    ID userid = user.id;

    QList<Task *> allTasks = (TaskManagerHelper::getTaskManager()->getTasks()).values();
    vector<Task> myTasks;
    QList<Task *>::iterator i;
    for (i = allTasks.begin(); i != allTasks.end(); ++i) {
        if ((*i)->userId==userid){
            myTasks.push_back(**i);
            cout << (*i)->userId << " " << (*i)->rawCommand << endl;
        }
    }

    return myTasks;

}

QMap<ID, Task*> TaskManager::getTasks() {
    return tasks;
}

ID TaskManager::addTask(ID userId, std::string rawCommand){

    qDebug() << tr("add task:")<<QThread::currentThreadId();

    Task*  task = new Task;
    task->taskId = nextTaskId;
    task->rawCommand = rawCommand;
    task->userId = userId;
    nextTaskId++;

    time_t now;
    time(&now);
    task->createdTime = now;
    task->status = TaskStatus::WAITTING;


    cout << *task << endl;


    tasks.insert(task->taskId,task);

    qint32 id = task->taskId;

    distributeTask(id);

    return task->taskId;//返回任务id.
}

Task TaskManager::getTask(ID taskId){

    if (tasks[taskId]) {
        Task task = *(tasks[taskId]);
        time_t now;
        time(&now);
        task.currentTime = now;
        return task;
    }
    else {
        cout << "Not found." << endl;
        Task* ret = new Task();
        return *ret;
    }
    
}

void TaskManager::stopAllTasks(){
    mWorkThreadPool.stopAll();
}

void TaskManager::distributeTask(ID taskId){


    qDebug() << tr("distributeTask()")<<QThread::currentThreadId();

    //查找可用线程
    WorkerThread * thread = mWorkThreadPool.findAvaiableTcpThread();

    if(thread == NULL){
        if(mWorkThreadPool.getThreadSize()>=mWorkThreadPool.getMaxThreadSize()){
             qDebug() << tr("Error: No avaiable thread for use. The thread pool is full, and size is:")<<mWorkThreadPool.getThreadSize();
             return;
        }
        else{
            //线程池未超出，创建新线程。
            thread = new WorkerThread();
            //把这个线程的事件，放在自己线程处理。
            thread->moveToThread(thread);

            if(thread != NULL){
                mWorkThreadPool.addNewWorkThread(thread);
            }
            else{
                qDebug() << tr("Error: No avaiable thread for use, fail to add new thread.");
                return;
            }
        }
    }


    thread->setWorkListener(this);
    thread->start();

    thread->assignTask(tasks[taskId]);

}


void TaskManager::onTaskDone(ID id){


    qDebug() << tr("The task done:")<<id;

     QList<Task *> allTasks = tasks.values();

     bool find = false;
     foreach(Task* task, allTasks)
     {
         if(task->status == TaskStatus::WAITTING){
             qDebug() << tr("Find next task from waiting to distribute..");
             distributeTask(task->taskId);
             find = true;
         }

     }

     if(!find){
         qDebug() << tr("No more task to distribute..");
     }

}



shared_ptr<TaskManager> TaskManagerHelper:: taskManager =  shared_ptr<TaskManager>(new TaskManager());

shared_ptr<TaskManager> TaskManagerHelper:: getTaskManager() {

    return taskManager;
}
