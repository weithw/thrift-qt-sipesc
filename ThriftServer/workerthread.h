#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>
#include "taskparser.h"
#include "../thrift/gen-cpp/Types_types.h"
#include "tasklistener.h"

using namespace org::ssdut::sipesc::network::types;


class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    ~WorkerThread();
   bool isAvaiable(); //线程是否空闲
   bool assignTask(Task * task); //给线程分配新任务

   void setWorkListener(TaskListener* listener);
  private:
    bool b_running;
    TaskParser taskPaser;
    Task* mTask;
    TaskListener *  onWorkListener;
private:
    void run();
    void reset();
signals:
    void updateStatus(qint32, QString); //报告任务执行过程中的状态信息
    void done(); // 任务执行完成，不论任务状态是 成功或失败，或其他状态。参数为任务id
    void newTaskAssigned(qint32);
public slots:
     void stop();//使线程停止执行.任务取消
private slots:
     void onNewTaskAssigned();
};

#endif // WORKERTHREAD_H
