#ifndef USERSERVICEHANDLER_H
#define USERSERVICEHANDLER_H


#include "database.h"

using namespace std;



using namespace org::ssdut::sipesc::network::types;

class UserServiceHandler: virtual public UserServiceIf
{
public:
 UserServiceHandler() {
   // Your initialization goes here
 }

 void login( ::org::ssdut::sipesc::network::types::AuthenticationResult& _return, const std::string& username, const std::string& password) {
   // Your implementation goes here
     if(testLogin(username,password)){
         _return.authenticationToken = "hello,"+username+"this,is,a,token";
     }else{
         SipescException ex;
        ex.errorCode = SipescErrorCode::INVALID_AUTH;
         ex.why  = "Wrong accouts!";
         throw ex;
     }
   printf("login\n");
 }

 void logout(const std::string& authenticationToken) {
   // Your implementation goes here
   printf("logout\n");
 }

 void refreshAuthentication( ::org::ssdut::sipesc::network::types::AuthenticationResult& _return, const std::string& authenticationToken) {
   // Your implementation goes here
   printf("refreshAuthentication\n");
 }

 void getUser( ::org::ssdut::sipesc::network::types::User& _return, const std::string& authenticationToken) {
   // Your implementation goes here
   printf("getUser\n");
 }

 void getPublicUserInfo( ::org::ssdut::sipesc::network::types::PublicUserInfo& _return, const std::string& username) {
   // Your implementation goes here
   printf("getPublicUserInfo\n");
 }
};

#endif // USERSERVICEHANDLER_H
