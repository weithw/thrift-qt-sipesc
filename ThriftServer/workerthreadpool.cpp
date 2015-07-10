#include "workerthreadpool.h"

#include <QDebug>

WorkerThreadPool:: WorkerThreadPool(int initSize, int maxThreadSize): QObject(0){

     qDebug()<<"Thread pool in thead:"<<QThread::currentThreadId();

    if(maxThreadSize <=0){
        maxThreadSize = 50;
    }

    if(initSize <= 0){
        initSize = 10;
    }

    if(initSize > maxThreadSize){
        initSize = maxThreadSize;
    }

    this->maxThreadSize = maxThreadSize;
    for(int i = 0;i < initSize; i++){
        WorkerThread * thread = new WorkerThread();

        if(thread != NULL){
            //把发送给该线程的事件放到它本身线程去执行。
            thread->moveToThread(thread);
            //线程添加到线程池中。
            workerThreads.append(thread);
        }
    }
}

WorkerThreadPool::~WorkerThreadPool(){
    maxThreadSize = 50;
    stopAll();
    qDeleteAll(workerThreads);
    workerThreads.clear();
}


WorkerThread* WorkerThreadPool:: findAvaiableTcpThread(){

    foreach(WorkerThread * thread, workerThreads){
        if(thread->isAvaiable()){
            return thread;
        }
    }
    return NULL;
}

void  WorkerThreadPool::addNewWorkThread(WorkerThread* worker){

    if(worker != NULL){
        workerThreads.append(worker);
        if(workerThreads.size() > maxThreadSize){
            maxThreadSize = workerThreads.size();
        }
    }



}

//获得当前线程池大小.
int  WorkerThreadPool::getThreadSize(){
    return workerThreads.size();
}

void WorkerThreadPool:: setMaxThreadSize(int maxSize){

    //最大容量
this->maxThreadSize = maxSize;
}
int WorkerThreadPool:: getMaxThreadSize(){
    return maxThreadSize;
}

void  WorkerThreadPool::stopAll(){
    //停止所有线程运行。
    foreach(WorkerThread* thread, workerThreads){
        thread->stop();
    }
}
