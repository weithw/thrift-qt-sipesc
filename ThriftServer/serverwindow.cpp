#include "serverwindow.h"
#include "ui_serverwindow.h"


#include <iostream>


using namespace std;


ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);

    cout<<"server window in thread:"<<QThread::currentThreadId()<<endl;

    initServer(10,1234);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

void ServerWindow::initServer(int workerCount, int port){

    this->workerCount = workerCount;
    this->port = port;

    protocolFactory =  shared_ptr<TProtocolFactory>(new TBinaryProtocolFactory());
    shared_ptr<NetworkServiceHandler> networkService = shared_ptr<NetworkServiceHandler>(new NetworkServiceHandler());
    processor= shared_ptr<TProcessor>(new NetworkServiceProcessor(networkService));


    threadManager =    shared_ptr<ThreadManager>(ThreadManager::newSimpleThreadManager(workerCount));
    threadFactory =   shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();

    mServer =  shared_ptr<TNonblockingServer>( new TNonblockingServer(processor, protocolFactory, port, threadManager) );

  //     shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  //     shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());

  //     mServer =  shared_ptr<TThreadPoolServer>
  //            (new TThreadPoolServer(processor,serverTransport
  //                               ,transportFactory ,protocolFactory,
  //                               threadManager));


}


void ServerWindow::start(){

    cout << "Starting the server..." << endl;

    DBHelper::getDatabase()->openConnection();
    mServer->serve();

}

void ServerWindow::stop(){
    cout<<"Stop the server..."<< endl;
    DBHelper::getDatabase()->closeConnection();
    TaskManagerHelper::getTaskManager()->stopAllTasks();
    mServer->stop();
    cout<<"Done."<<endl;
    QApplication::exit();
}

void ServerWindow:: show(){
    QMainWindow::show();
}
