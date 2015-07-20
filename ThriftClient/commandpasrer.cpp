#include "commandparser.h"

CommandParser::CommandParser(QObject *parent) :
    QObject(parent)
{
}

void CommandParser::parse(QString rawCommand){

    emit  updateStatus( "start to parse command:" + rawCommand+"\n");

    //在这里写下对命令的解释，和, 我下面给出的是示例。你需要完整解析

    if(rawCommand.compare("login",Qt::CaseInsensitive)==0){

        //解析出用户名和密码。
        std::string username="jin";
        std::string password = "123";

        //调用登录
        AuthenticationResult result;
        Globals::networkService->login(result, username, password);

    }else if(rawCommand.compare("publicinfo",Qt::CaseInsensitive)==0){

        //解析出用户名和密码。
        std::string username="jin";

        //调用登录
        PublicUserInfo result;
        Globals::networkService->getPublicUserInfo(result, username);

    }else if(rawCommand.compare("logut",Qt::CaseInsensitive)==0){

        //调用退出接口。

    }else if(rawCommand.compare("show  --task --id 123",Qt::CaseInsensitive)==0){

        //调用获取指定任务接口。

    }else if(rawCommand.contains("call")){
        //调用服务器的提交命令接口。

      CallResult result;
      Globals::networkService->postTask( result, Globals::authResult.authenticationToken, rawCommand.toStdString());

      emit  updateStatus( "post a task\n");

    }else{

       emit  updateStatus( "Usage: xxxxxxxxxxxxx.....xxx...[in commandparser.cpp]\n");
    }

}
