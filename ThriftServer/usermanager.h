#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QObject>
#include <qmap.h>
#include "database.h"


#include "../thrift/gen-cpp/Types_types.h"

using namespace std;
using namespace org::ssdut::sipesc::network::types;

class UserManager : public QObject
{
    Q_OBJECT
public:
    explicit UserManager(QObject *parent = 0);

    User getUserByToken(string token);

    string createTokenForUser(User user);

    AuthenticationResult login(const std::string & username,const std::string & pwd);
    PublicUserInfo getPublicUserInfo(const std::string & username);
private:

   QMap<std::string,User> users; // token-user map.

signals:
    
public slots:
    
};



class UserManagerHelper{
public:
    static shared_ptr<UserManager> getUserManager();
private:
     static shared_ptr<UserManager> userManager;
};



#endif // USERMANAGER_H
