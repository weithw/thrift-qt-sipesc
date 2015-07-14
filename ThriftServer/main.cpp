#include <QtGui/QApplication>
#include "serverwindow.h"
#include <QDebug>

#include <iostream>
#include <QThread>

using namespace std;


int main(int argc, char **argv) {

    QApplication app(argc,argv);

     qDebug()<<"main thead:"<<QThread::currentThreadId();

    ServerWindow server;
    server.start();

    return app.exec();
}
