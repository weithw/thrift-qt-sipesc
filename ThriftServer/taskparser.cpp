#include "taskparser.h"
#include <QApplication>
#include <qdebug.h>
#include <mpluginmanager.h>
#include <mextensionmanager.h>
#include <mobjectmanager.h>
#include <merrormanager.h>
#include <iostream>
#include <org.ssdut.plugin.helloworld.feature.messageprovider.h>
#include <org.ssdut.plugin.helloworld.feature.messagereceiver.h>
using namespace org::ssdut::plugin::helloworld::feature;



int test() {
    MPluginManager::initialize(false);

    MPluginManager pmanager = MPluginManager::getManager();
    //Q_ASSERT(!pmanager.isNull());
    bool ok = pmanager.loadAllPlugins();
    Q_ASSERT(ok);

    //
    MExtensionManager extManager = MExtensionManager::getManager();
    //Q_ASSERT(!extManager.isNull());

    QString name = "org.ssdut.plugin.helloworld.feature.MessageProvider";
    MessageProvider provider = extManager.createExtension(name);

    name = "org.ssdut.plugin.helloworld.feature.MessageReceiver";
    MessageReceiver receiver = extManager.createExtension(name);

    if(provider.isNull() || receiver.isNull()){
      printf("Error: Can not create extensions.\n");


        MErrorManager manager=MErrorManager::getManager();
        int count=manager.getErrorCount();
        for(int i=0; i<count; i++)
        {
            MErrorObject error=manager.getErrorAt(i);
            printf("%s\n", qPrintable(error.toString()));
        }
      return 0;
    }

    receiver.showMessage(provider.getMessage());
    return 0;
}
TaskParser::TaskParser(QObject *parent) :
    QObject(parent)
{
}


void  TaskParser::parse(Task *task) throw(SipescException){


    QString taskCommand = QString::fromUtf8(task->rawCommand.data());
    std::cout << "start to parse command:" << task->rawCommand << " [in server/TaskParser.cpp:parse()]" << std::endl;
    emit  updateStatus( "start to parse command:" + taskCommand + "[in server/TaskParser.cpp:parse()]");



   //在这里写下对命令的解释，和, 我下面给出的是示例。你需要完整解析

    if(taskCommand.compare("helloworld",Qt::CaseInsensitive)==0){



    }else if(taskCommand.compare("plugin2",Qt::CaseInsensitive)==0){


    }else if(taskCommand.compare("plugin3",Qt::CaseInsensitive)==0){



    }else if(taskCommand.compare("call",Qt::CaseInsensitive)==0){

        //ghw test

        // pid_t pid;  
        // pid = fork();  
        // // son process create here, exact copy from parent process  
        // // son process will execute the main funciton after parent process  
        // if(pid<0) {  
        //     return;  
        // }  
        // if(pid==0) {  
        //     int ret;
        //     ret =execl("./helloworld", "hello", NULL);
        // }else {  
        //     ;
        // }  
        
        test();


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
