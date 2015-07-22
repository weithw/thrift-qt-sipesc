#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include "workerthreadpool.h"
#include "workerthread.h"
#include "database.h"
#include "tasklistener.h"
#include "../thrift/gen-cpp/Types_types.h"

using namespace org::ssdut::sipesc::network::types;


class TaskManager : public QObject, public TaskListener
{
    Q_OBJECT
public:
    explicit TaskManager(QObject *parent = 0);
    
    ~TaskManager();

    ID addTask(ID userId,std::string rawCommand);

    Task getTask(ID taskId);

    void stopAllTasks();

private:

    ID nextTaskId; //下一个任务的ID号，这个ID最好持久化到数据库中，这样下次启动的时候仍然不会重复之前的ID。

    QMap<ID, Task*> tasks;

    WorkerThreadPool mWorkThreadPool;

   QTimer * timer;

   void distributeTask(ID);

signals:
    void newTaskAdded(qint32);
public slots:
    void onTaskDone(ID);
};


class TaskManagerHelper{
public:
    static shared_ptr<TaskManager> getTaskManager();
private:
    static shared_ptr<TaskManager> taskManager;
};

#endif // TASKMANAGER_H
