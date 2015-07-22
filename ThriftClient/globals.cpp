#include "globals.h"

Globals::Globals(QObject *parent) :
    QObject(parent)
{
}

shared_ptr<TTransport> Globals::transport;

shared_ptr<NetworkServiceClient> Globals::networkService;

shared_ptr<TProtocol>  Globals:: protocol;


AuthenticationResult Globals:: authResult;

void Globals::initServices(string host, int port){

    boost::shared_ptr<TTransport> socket(new TSocket(host, port));
    transport = shared_ptr<TTransport>(new TFramedTransport(socket));
    protocol = shared_ptr<TProtocol>(new TBinaryProtocol(Globals::transport));


    networkService = shared_ptr<NetworkServiceClient>(new NetworkServiceClient(protocol));

}
