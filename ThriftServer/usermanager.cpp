#include "usermanager.h"
#include "time.h"

UserManager::UserManager(QObject *parent) :
    QObject(parent)
{

}

User UserManager::getUserByToken(string token){
    if(users.contains(token)){
        return users[token];
    }
    cout<<"user token not found"<<endl;
    User nullUser;
    nullUser.id = -1;

    return nullUser;
}

std::string UserManager::createTokenForUser(User user){
  std::string token = "hello,"+user.userName+"this,is,a,token";//应该随机生成
  return token;
}

AuthenticationResult  UserManager::login(const std::string & username,const std::string & pwd){

    AuthenticationResult result;

    if( DBHelper::getDatabase()->login(username,pwd)){

        User user =  DBHelper::getDatabase()->getUser(username); //从数据库中获得用户

        result.authenticationToken = createTokenForUser(user);

        result.user  = user;
        users.insert(result.authenticationToken,user); //插入到用户列表
        
        time_t now;
        time(&now);
        result.currentTime = now;

        result.expiration = now + 3600; //一小时后失效.

    }else{
        SipescException ex;
        ex.errorCode = SipescErrorCode::INVALID_AUTH;
        ex.why = "Wrong account.";
        throw ex;
    }

    return result;
}

void UserManager::logout(const string &authenticationToken){

    users.remove(authenticationToken);
}

shared_ptr<UserManager> UserManagerHelper:: userManager =  shared_ptr<UserManager>(new UserManager());
shared_ptr<UserManager> UserManagerHelper:: getUserManager() {

    return userManager;
}

