#include "taskparser.h"

TaskParser::TaskParser(QObject *parent) :
    QObject(parent)
{
}


void  TaskParser::parse(Task *task) throw(SipescException){


    QString taskCommand = QString::fromUtf8(task->rawCommand.data());
    std::cout << "[in server/TaskParser.cpp:parse]" << std::endl;
    emit  updateStatus( "start to parse command:" + taskCommand + "[in server/TaskParser.cpp]");



   //在这里写下对命令的解释，和, 我下面给出的是示例。你需要完整解析

   if(taskCommand.compare("helloworld",Qt::CaseInsensitive)==0){



   }else if(taskCommand.compare("plugin2",Qt::CaseInsensitive)==0){


   }else if(taskCommand.compare("plugin3",Qt::CaseInsensitive)==0){



   }else{
       QString useage("Usage: xxxxxxxxxxxxx.....xxx...\n");
               emit  updateStatus(useage);
       SipescException ex;
       ex.errorCode = SipescErrorCode::UNSUPPORTED_OPERATION;
       ex.why = useage.toStdString();


       task->status = TaskStatus::ERROR;

       throw ex;
   }


   task->status = TaskStatus::SUCC;


}
