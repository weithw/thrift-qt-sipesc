#include "commandparser.h"
#include<qstringlist.h>
#include<sstream>



CommandParser::CommandParser(QObject *parent) :
    QObject(parent)
{
}

void CommandParser::parse(QString rawCommand){

    emit  updateStatus( "start to parse command:" + rawCommand+"\n");


    //在这里写下对命令的解释，和, 我下面给出的是示例。你需要完整解析

    //rawCommand.replace(QRegExp("[\\s]+"), " ");
     QStringList rawCommandList=rawCommand.split(" ");

     if(rawCommandList[0].compare("logout",Qt::CaseInsensitive)==0){

		Globals::networkService->logout(Globals::authResult.authenticationToken);
         emit updateStatus( "logout\n");


     }else if(rawCommandList[0].compare("refresh",Qt::CaseInsensitive)==0){

        AuthenticationResult resultOfRefresh;
        Globals::networkService->refreshAuthentication(resultOfRefresh,Globals::authResult.authenticationToken);
         emit updateStatus( "refreshAuthentication\n");

     }else if(rawCommandList[0].compare("getUser",Qt::CaseInsensitive)==0){

		User user;
		Globals::networkService->getUser(user,Globals::authResult.authenticationToken);
        // emit updateStatus( "getUser\n");
         std::ostringstream os;
         os<<user;
         QString info;
         string temp =os.str();
         info=QString::fromStdString(temp);
        emit updateStatus( info);

     }else if(rawCommandList[0].compare("getInfo",Qt::CaseInsensitive)==0){

        if(rawCommandList.size()==2){
            string userName=rawCommandList[1].toStdString();
			PublicUserInfo info;
			Globals::networkService->getPublicUserInfo(info,userName);
            std::ostringstream os;
            os<<info;
            QString showInfo;
            string temp =os.str();
            showInfo=QString::fromStdString(temp);
           emit updateStatus( showInfo);
        }else emit updateStatus( "ERROR!\nUsage:getInfo userName\n");
         emit updateStatus( "getPublicUserInfo\n");

     }else if(rawCommandList[0].compare("getTask",Qt::CaseInsensitive)==0){
		
        if(rawCommandList.size()==2){
		
            Task resultOfGetTask;
            ID taskID=rawCommandList[1].toInt();
            Globals::networkService->getTask(resultOfGetTask,Globals::authResult.authenticationToken,taskID);
            if (resultOfGetTask.taskId != 0) {
                std::ostringstream os;
                os<<resultOfGetTask;
                QString showInfo;
                string temp =os.str();
                showInfo=QString::fromStdString(temp);
                emit updateStatus( showInfo);
            }
            else
                emit updateStatus( "ERROR!\nNot found task.\n");
        }else 
            emit updateStatus( "ERROR!\nUsage:getTask taskID\n");
		emit updateStatus( "getTask\n");

     }else if(rawCommandList[0].compare("listTask",Qt::CaseInsensitive)==0){

        vector<Task> tasks;
        Globals::networkService->listTasks(tasks,Globals::authResult.authenticationToken);
        emit updateStatus( "listTasks\n");
        vector<Task>::iterator iter;  
        std::ostringstream os;
        
        QString showInfo;
        for (iter=tasks.begin();iter!=tasks.end();iter++)  
        {  
            os<<*iter;
        } 
        string temp =os.str();
        showInfo=QString::fromStdString(temp);
        emit updateStatus( showInfo);

     }else if(rawCommandList[0].compare("call",Qt::CaseInsensitive)==0){
		
		CallResult result;
		Globals::networkService->postTask( result, Globals::authResult.authenticationToken, rawCommand.toStdString());
         emit updateStatus( "postTask\n");

     }else if(rawCommandList[0].compare("help",Qt::CaseInsensitive)==0){

         QString commandInfo=" logout\nrefresh\t\tto refresh authentication\ngetuser\t\tget current user infomation\ngetinfo\t[userName]\tget userName and Id\ngetTask\t[taskID]\tget task information\nlistTask\t\tget all task of user\ncall\t[target][..]\tpost a task\n";
         emit updateStatus(commandInfo);
     }
/*
    if(rawCommand.compare("login",Qt::CaseInsensitive)==0){

        //解析出用户名和密码。
        std::string username="jin";
        std::string password = "123";

        //调用登录
        AuthenticationResult result;
        Globals::networkService->login(result, username, password);

    }else if(rawCommand.compare("logut",Qt::CaseInsensitive)==0){

        //调用退出接口。

    }else if(rawCommand.compare("show  --task --id 123",Qt::CaseInsensitive)==0){

        //调用获取指定任务接口。

    }else if(rawCommand.compare("call",Qt::CaseInsensitive)==0){
        //调用服务器的提交命令接口。

      CallResult result;
      Globals::networkService->postTask( result, Globals::authResult.authenticationToken, rawCommand.toStdString());

      emit  updateStatus( "post a task\n");

    } */
else{

       emit  updateStatus( "Command Not Found!");
    }

}
