#ifndef NETWORKSERVICEHANDLER_H
#define NETWORKSERVICEHANDLER_H

#include <QObject>

#include "../thrift/gen-cpp/NetworkService.h"
#include "usermanager.h"
#include "taskmanager.h"

#include <QFile>
#include <iostream>
#include <QMetaType>
#include <QDebug>

using namespace org::ssdut::sipesc::network::service;
using namespace org::ssdut::sipesc::network::types;
using namespace std;

class NetworkServiceHandler : virtual public NetworkServiceIf
{
public:
    explicit NetworkServiceHandler(){

         qRegisterMetaType<ID>("TYPES_ID");
    }
    

    /**
       * 测试能否通信。
       */
      void ping( ::org::ssdut::sipesc::network::types::CallResult& _return) {
        // Your implementation goes here
        printf("ping\n");
      }

      /**
       * 登录到服务器
       *
       * @param username
       * @param password
       */
      void login( ::org::ssdut::sipesc::network::types::AuthenticationResult& _return, const std::string& username, const std::string& password) {
        // Your implementation goes here


          _return =   UserManagerHelper::getUserManager()->login(username,password);

          printf("login\n");
      }

      /**
       * 退出登录
       *
       * @param authenticationToken
       */
      void logout(const std::string& authenticationToken) ;

      /**
        *注册新用户
        *
        *@param newUser
        *@param password
        */
     bool regist(const  ::org::ssdut::sipesc::network::types::User& newUser, const std::string& password);


      /**
       * 更新会话
       *
       * @param authenticationToken
       */
      void refreshAuthentication( ::org::ssdut::sipesc::network::types::AuthenticationResult& _return, const std::string& authenticationToken);

      /**
       * 获得当前账户信息
       *
       * @param authenticationToken
       */
      void getUser( ::org::ssdut::sipesc::network::types::User& _return, const std::string& authenticationToken) ;


      /**
       * 获得用户公开信息
       *
       * @param username
       */
        void getPublicUserInfo( ::org::ssdut::sipesc::network::types::PublicUserInfo& _return, const std::string& username);

      /**
       * 获得用户的指定任务信息。
       *
       * @param authenticationToken
       * @param taskId
       */
      void getTask( ::org::ssdut::sipesc::network::types::Task& _return, const std::string& authenticationToken, const  ::org::ssdut::sipesc::network::types::ID taskId);

      /**
       * 获得当前用户的所有任务。
       *
       * @param authenticationToken
       */
      void listTasks(std::vector< ::org::ssdut::sipesc::network::types::Task> & _return, const std::string& authenticationToken);

      /**
       * 提交一个任务
       *
       * @param authenticationToken
       * @param rawCommand
       */
      void postTask( ::org::ssdut::sipesc::network::types::CallResult& _return, const std::string& authenticationToken, const std::string& rawCommand) {
        // Your implementation goes here
        printf("postTask\n");


        qDebug()<<"before post task in thread:"<<QThread::currentThreadId();

        User user =  UserManagerHelper::getUserManager()->getUserByToken(authenticationToken);

//        if(user.id <=0){
//            SipescException ex;
//            ex.errorCode = SipescErrorCode::INVALID_AUTH;
//            throw ex;
//        }

        //调用任务管理器
        int32_t taskId = TaskManagerHelper::getTaskManager()->addTask(user.id,rawCommand);

        _return.resultCode = ResultCode::Success;

        _return.i32Result = taskId;

         qDebug()<<"after post task in thread:"<<QThread::currentThreadId();

      }

      /**
       * 上传一部分文件数据到服务器，用户目录下，这个版本用于不大的文件
       *
       * @param authenticationToken
       * @param fileName
       * @param size
       * @param data
       */
      int64_t uploadFile(const std::string& authenticationToken, const std::string& fileName, const int64_t size, const  ::org::ssdut::sipesc::network::types::Bytes& data) {
          // Your implementation goes here
          printf("uploadFile\n");
          User tmp_user = UserManagerHelper::getUserManager()->getUserByToken(authenticationToken);
          cout << tmp_user << endl;
          QString final_filename = QString("user/")+ QString::fromStdString(tmp_user.userName) + QString("/") + QString::fromStdString(fileName);

          QTextStream cout(stdout, QIODevice::WriteOnly); 
          QFile localFile(final_filename);

          cout<<"Open file to write:"<<final_filename<<"\n";

          if(!localFile.open(QFile::WriteOnly)){
              cout<<"Can not open file:"<<final_filename<<endl;
              return -1;
          }


          cout<<"file size:"<<size<<endl;
          cout<<"data size:"<<data.size()<<endl;
          //QByteArray inBlock = socket->read(qMin(comingBytes, totalBytes - bytesReceived));
          qint64 successWritten = localFile.write(data.data(),size);

          cout<<"written file size:"<<successWritten<<endl;

          localFile.close();
          return successWritten;

      }

      /**
       * 删除服务器文件
       *
       * @param authenticationToken
       * @param fileName
       */
      void deleteFile( ::org::ssdut::sipesc::network::types::CallResult& _return, const std::string& authenticationToken, const std::string& fileName) {
        // Your implementation goes here
        printf("deleteFile\n");
      }

      /**
       * 下载文件
       *
       * @param authenticationToken
       * @param fileName
       */
      void downloadFile( ::org::ssdut::sipesc::network::types::Bytes& _return, const std::string& authenticationToken, const std::string& fileName) {
        // Your implementation goes here
        printf("downloadFile\n");
      }

};

#endif // NETWORKSERVICEHANDLER_H
