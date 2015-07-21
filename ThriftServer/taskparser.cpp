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
#include <string>
using namespace org::ssdut::plugin::helloworld::feature;
using namespace std;


//
int call_helloworld(QString& command) {
    cout << "in call_helloworld()!!!" << " para:" << command.toLatin1().data() << endl;
    MPluginManager::initialize(false);

    MPluginManager pmanager = MPluginManager::getManager();

    QString path = "/home/ghw/.sipesc/lib/plugins/debug/org.ssdut.plugin.helloworld_1.0.0.sep";
    pmanager.loadPlugin(path);
    QStringList fonts = pmanager.getLoadedPluginList();

    // for (int i = 0; i < fonts.size(); ++i)
    //       std::cout << fonts.at(i).toLocal8Bit().constData() <<std::endl;

    //
    MExtensionManager extManager = MExtensionManager::getManager();
    Q_ASSERT(!extManager.isNull());

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

    receiver.showMessage("123");

    extManager.cleanup();
    MPluginManager::cleanup();
    return 0;
}
TaskParser::TaskParser(QObject *parent) :
    QObject(parent)
{
}


void  TaskParser::parse(Task *task) throw(SipescException){
    task->status = TaskStatus::RUNNING;

    QString taskCommand = QString::fromUtf8(task->rawCommand.data());
    cout << "start to parse command:" << task->rawCommand << " [in server/TaskParser.cpp:parse()]" << endl;
    emit  updateStatus( "start to parse command:" + taskCommand + "[in server/TaskParser.cpp:parse()]");



   //在这里写下对命令的解释, 我下面给出的是示例。你需要完整解析

    QStringList strlist = taskCommand.trimmed().split(" ");
    if (strlist.length() >= 2) {
        QString is_call = strlist.at(0).toLocal8Bit().data();
        QString plugin_name = strlist.at(1).toLocal8Bit().data();

        //get the parameter
        QString command_para = taskCommand.trimmed().mid(is_call.length()).trimmed().mid(plugin_name.length()).trimmed();
        if(is_call.compare("call",Qt::CaseInsensitive)==0){
            cout << "plugin name: " << plugin_name.toLatin1().data() << endl;
            if(plugin_name.compare("helloworld",Qt::CaseInsensitive)==0){
                call_helloworld(command_para);

            }else if(plugin_name.compare("plugin2",Qt::CaseInsensitive)==0){


            }else if(plugin_name.compare("plugin3",Qt::CaseInsensitive)==0){



            }else {
                QString err_info("No such plugin.");
                emit  updateStatus(err_info);
                SipescException ex;
                ex.errorCode = SipescErrorCode::UNSUPPORTED_OPERATION;
                ex.why = err_info.toStdString();
                task->status = TaskStatus::ERROR;
                throw ex;
            }
            
        }else{
            QString useage("Usage: xxxxxxxxxxxxx.....xxx...\n");
                emit  updateStatus(useage);
            SipescException ex;
            ex.errorCode = SipescErrorCode::UNSUPPORTED_OPERATION;
            ex.why = useage.toStdString();


            task->status = TaskStatus::ERROR;

            throw ex;
        }
    } else {
        QString err_info("Too few arguments.");
        emit  updateStatus(err_info);
        SipescException ex;
        ex.errorCode = SipescErrorCode::UNSUPPORTED_OPERATION;
        ex.why = err_info.toStdString();
        task->status = TaskStatus::ERROR;
        throw ex;
    }

    task->status = TaskStatus::SUCC;


}
