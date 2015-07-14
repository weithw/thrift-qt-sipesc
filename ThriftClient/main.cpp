#include <QtGui/QApplication>
#include "clientwindow.h"
#include "logindialog.h"
#include "clientwindow.h"

#include "globals.h"

#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/protocol/TMultiplexedProtocol.h>


using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


using namespace org::ssdut::sipesc::network::types;
using namespace org::ssdut::sipesc::network::service;

using boost::shared_ptr;

#include <QTextCodec>
#include <QTextStream>
#include <QDebug>

int main(int argc, char** argv) {

  int mainResult = 0;

  Globals::initServices("localhost",1234);

  try {
    Globals::transport->open();

    try{

        CallResult result;

        Globals::networkService ->ping(result);
        if(result.resultCode == ResultCode::Success){
            cout<<"Ping task server ok.."<<endl;
        }else{
            cout<<"Ping task server fail!"<<endl;
        }


    } catch (SipescException & ex) {
        cout<<ex.errorCode<<","<<ex.why;
    }


    QApplication app(argc, argv);
    LoginDialog loginDialog;
    ClientWindow window;

//   if( loginDialog.exec() != QDialog::Accepted){
//       Globals::transport->close();
//       return -1;
//    }

    window.show();
    mainResult = app.exec();

    Globals::transport->close();



  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }

  return mainResult;
}
