#ifndef WORKERTHREADPOOL_H
#define WORKERTHREADPOOL_H

#include <QObject>
#include <QList>
#include <QDebug>
#include "workerthread.h"


class WorkerThreadPool : public QObject
{
    Q_OBJECT
public:
    explicit WorkerThreadPool(int initSize, int maxThreadSize = 50);
    ~WorkerThreadPool();
private:
    int maxThreadSize;
    QList<WorkerThread*> workerThreads;
public:
    WorkerThread* findAvaiableTcpThread();
    void addNewWorkThread(WorkerThread* worker);
    int getThreadSize(); //获得当前线程池大小.
    void setMaxThreadSize(int maxSize); //最大容量
    int getMaxThreadSize();
    void stopAll(); //停止所有线程运行。
signals:
    
public slots:
    
};

#endif // WORKERTHREADPOOL_H
