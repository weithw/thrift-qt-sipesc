#ifndef GLOBALS_H
#define GLOBALS_H

#include <QObject>

#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/protocol/TMultiplexedProtocol.h>
#include <thrift/protocol/TProtocol.h>

#include "../thrift/gen-cpp/NetworkService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


using namespace org::ssdut::sipesc::network::types;
using namespace org::ssdut::sipesc::network::service;

using boost::shared_ptr;


class Globals : public QObject
{
    Q_OBJECT
public:
     explicit Globals(QObject *parent = 0);
     static shared_ptr<TTransport> transport;
     static shared_ptr<NetworkServiceClient> networkService;
     static shared_ptr<TProtocol> protocol;

     static void initServices(std::string host, int port);

     static AuthenticationResult authResult;
signals:
    
public slots:
    
};

#endif // GLOBALS_H
