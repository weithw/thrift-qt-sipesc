#ifndef TASKSERVICEHANDLER_H
#define TASKSERVICEHANDLER_H

#include "../thrift/gen-cpp/TaskService.h"
#include <QFile>

#include <iostream>

#include "taskparser.h"
#include "globals.h"

using namespace std;
using namespace org::ssdut::sipesc::network::tasks;
using namespace org::ssdut::sipesc::network::types;

class TaskServiceHandler : virtual public TaskServiceIf {

public:
  TaskServiceHandler() {
    // Your initialization goes here
  }

  TaskParser taskPaser;

  /**
   * 测试能否通信。
   */
  void ping( ::org::ssdut::sipesc::network::types::CallResult& _return) {
    // Your implementation goes here
    printf("ping\n");
  }

  void getTask( ::org::ssdut::sipesc::network::types::Task& _return, const std::string& authenticationToken, const  ::org::ssdut::sipesc::network::types::TaskId taskId) {
    // Your implementation goes here

    printf("getTask\n");
  }

  /**
   * 获得当前用户的所有命令。
   *
   * @param authenticationToken
   */
  void listTasks(std::vector< ::org::ssdut::sipesc::network::types::Task> & _return, const std::string& authenticationToken) {
    // Your implementation goes here
    printf("listTasks\n");
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


    QFile localFile(QString::fromStdString(fileName));

    cout<<"Open file to write:"<<fileName<<"\n";

    if(!localFile.open(QFile::WriteOnly)){
        cout<<"Can not open file:"<<fileName<<endl;
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
    * 提交一个命令
    *
    * @param authenticationToken
    * @param rawCommand
    */
   void postCommand( ::org::ssdut::sipesc::network::types::CallResult& _return, const std::string& authenticationToken, const std::string& rawCommand) {
     // Your implementation goes here
     printf("postCommand\n");

//     //调用任务解释器解释命令
//     Task task = taskPaser.parse(QString::fromStdString(rawCommand));

     //调用任务管理器
     int32_t taskId = Globals::taskManager->addTask(rawCommand);

     _return.resultCode = ResultCode::Success;

     _return.i32Result = taskId;

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

#endif // TASKSERVICEHANDLER_H
