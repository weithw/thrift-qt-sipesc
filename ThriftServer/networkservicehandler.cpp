#include "networkservicehandler.h"
#include"time.h"
#include<sstream>

void  NetworkServiceHandler::logout(const std::string& authenticationToken) {
    UserManagerHelper::getUserManager()->logout(authenticationToken);
  printf("logout\n");
}

/**
 * 更新会话
 *
 * @param authenticationToken
 */
void NetworkServiceHandler::refreshAuthentication( ::org::ssdut::sipesc::network::types::AuthenticationResult& _return, const std::string& authenticationToken) {
  // Your implementation goes here
    time_t now;
    time(&now);

    _return.__set_user(UserManagerHelper::getUserManager()->getUserByToken(authenticationToken));
    _return.__set_currentTime(now);
    _return.__set_expiration(now+3600);
    _return.__set_authenticationToken(authenticationToken);
  printf("refreshAuthentication\n");
}

/**
 * 获得当前账户信息
 *
 * @param authenticationToken
 */
void NetworkServiceHandler::getUser( ::org::ssdut::sipesc::network::types::User& _return, const std::string& authenticationToken) {

    _return=UserManagerHelper::getUserManager()->getUserByToken(authenticationToken);


}
/**
  *注册新用户
  *
  *@param newUser
  *@param password
  */
bool NetworkServiceHandler::regist(const  ::org::ssdut::sipesc::network::types::User& newUser, const std::string& password){

        return DBHelper::getDatabase()->regist(newUser,password);
}

/**
 * 获得用户公开信息
 *
 * @param username
 */
void NetworkServiceHandler::getPublicUserInfo( ::org::ssdut::sipesc::network::types::PublicUserInfo& _return, const std::string& username) {

    org::ssdut::sipesc::network::types::User user;
   user= DBHelper::getDatabase()->getUser(username);

    _return.__set_userId(user.id);
    _return.__set_username(user.userName);
}

/**
 * 获得用户的指定任务信息。
 *
 * @param authenticationToken
 * @param taskId
 */
void NetworkServiceHandler::getTask( ::org::ssdut::sipesc::network::types::Task& _return, const std::string& authenticationToken, const  ::org::ssdut::sipesc::network::types::ID taskId) {

    Task task = TaskManagerHelper::getTaskManager()->getTask(taskId);
    _return.__set_taskId(task.taskId);
    _return.__set_userId(task.userId);
    _return.__set_rawCommand(task.rawCommand);
    _return.__set_createdTime(task.createdTime);
}

/**
 * 获得当前用户的所有任务。
 *
 * @param authenticationToken
 */
void NetworkServiceHandler::listTasks(std::vector< ::org::ssdut::sipesc::network::types::Task> & _return, const std::string& authenticationToken) {
    // Your implementation goes here ——TaskManger中没有相关方法
    printf("listTasks\n");

    std::vector<Task> tasks = TaskManagerHelper::getTaskManager()->listUserTasks(authenticationToken);
    vector<Task>::iterator iter;  
    for (iter=tasks.begin();iter!=tasks.end();iter++)  
    {  
        Task tmp;
        tmp.__set_taskId(iter->taskId);
        tmp.__set_userId(iter->userId);
        tmp.__set_rawCommand(iter->rawCommand);
        tmp.__set_createdTime(iter->createdTime);
        _return.push_back(tmp);
    } 

}

