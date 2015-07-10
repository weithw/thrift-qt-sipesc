#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include <QObject>
#include <QString>

#include <iostream>

#include "globals.h"

#include <thrift/Thrift.h>



using namespace org::ssdut::sipesc::network::service;
using namespace org::ssdut::sipesc::network::types;


using boost::shared_ptr;
using namespace std;
using namespace apache::thrift;


class CommandParser : public QObject
{
    Q_OBJECT
public:
    explicit CommandParser(QObject *parent = 0);
    
    void parse(QString rawCommand);

private:


signals:

    void updateStatus(QString);

public slots:
    
};

#endif // COMMANDPARSER_H
