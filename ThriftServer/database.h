#ifndef DATABASE_H
#define DATABASE_H


#include<QSqlDatabase>
#include<QSqlQuery>
#include <QTextCodec>
#include <QByteArray>
#include <QDebug>

#include <iostream>
#include "../thrift/gen-cpp/Types_types.h"


using namespace std;
using namespace org::ssdut::sipesc::network::types;

using boost::shared_ptr;

extern QString s2q(const std::string &s);

extern string q2s(const QString &s);


class Database
{
public:
    Database();
    bool openConnection();
    bool login(const std::string & username,const std::string & pwd);
    User getUser(const std::string& userName);
    QString getUsernameById(int id);
    void closeConnection();
    void create();
    bool regist(const User& newUser, const std::string& password);
private:
    QSqlDatabase db;
};


class DBHelper
{
public:
    static shared_ptr<Database> getDatabase();
private:
    static shared_ptr<Database> db;
};

#endif // DATABASE_H
