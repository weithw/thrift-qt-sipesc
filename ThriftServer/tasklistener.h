#ifndef TASKLISTENER_H
#define TASKLISTENER_H

#include "../thrift/gen-cpp/Types_types.h"

using namespace org::ssdut::sipesc::network::types;

/**
  * 任务监听器。
  */
class TaskListener
{
public:
    TaskListener();
    virtual void onTaskDone(ID)=0;
};

#endif // TASKLISTENER_H
