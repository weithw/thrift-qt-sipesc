#ifndef TASKPARSER_H
#define TASKPARSER_H

#include <QObject>

#include "../thrift/gen-cpp/Types_types.h"

using namespace org::ssdut::sipesc::network::types;

class TaskParser : public QObject
{
    Q_OBJECT
public:
    explicit TaskParser(QObject *parent = 0);
    
    void parse(Task * task) throw (SipescException);

signals:
    void updateStatus(QString);
public slots:
    
};

#endif // TASKPARSER_H
