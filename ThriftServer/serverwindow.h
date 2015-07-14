#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>





#include "networkservicehandler.h"
#include "database.h"
#include "usermanager.h"
#include "taskmanager.h"




#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/processor/TMultiplexedProcessor.h>


using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;



using boost::shared_ptr;
using namespace org::ssdut::sipesc::network::service;
using namespace org::ssdut::sipesc::network::types;

namespace Ui {
class ServerWindow;
}

class ServerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ServerWindow(QWidget *parent = 0);
    ~ServerWindow();
    void start();
    void stop();
    void show();
private:
    Ui::ServerWindow *ui;


    void initServer(int workerCount,int port);


     shared_ptr<TProtocolFactory> protocolFactory;
     shared_ptr<TProcessor> processor;

     int workerCount;
     int port;

     shared_ptr<ThreadManager> threadManager;
     shared_ptr<PosixThreadFactory> threadFactory;

     shared_ptr<TServer> mServer;

};

#endif // SERVERWINDOW_H
