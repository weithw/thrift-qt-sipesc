#include "database.h"

Database::Database()
{
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    create();
}

void Database::create(){

    if(!db.open()){
        return;
    }

    QSqlQuery query;
    query.exec("create table user (id int primary key,username varchar(20), password varchar(80))");
    query.exec("insert into user values(0,'xu','123')");
    query.exec("insert into user values(1,'zhang','123')");
    query.exec("insert into user values(2,'jin','123')");
    QString sql = "insert into user values(3,'我','123')";
    qDebug()<<"测试："<<sql;
    cout<<"sql:"<<sql.toStdString();
    query.exec(sql);

}

bool Database::openConnection(){
    if(!db.open()){

        return true;
    }
    return false;
}

void Database::closeConnection(){
    if(db.isOpen()){
       db.close();
    }
}


extern QString s2q(const std::string &s)
{

   //return QString::fromUtf8(s.data(),s.size()); //用于显示时好使
    return QString::fromStdString(s);//用于比较时好使
}

extern string q2s(const QString &s)
{
    //return s.toStdString();//汉字失真
    return std::string(s.toUtf8().constData());//无损
}


bool Database::login(const std::string & username,const std::string & pwd){


    cout<<"User:"<<username<<" Try to login."<<endl;

    bool ok = false;
    QSqlQuery q;

    std::string str= "select password from user where username='"+username+"'";

    QString sql=QString::fromStdString(str) ;
    QString qPw = QString::fromStdString(pwd);
     q.exec(sql);
     if(q.next()){
         QString dbPwd = q.value(0).toString();

         if(!dbPwd.isEmpty() && dbPwd.compare(qPw,Qt::CaseInsensitive) == 0){
            ok = true;
         }

     }

     cout<<"login result="<<ok<<endl;
     return ok;
}
bool Database::getPublicUserInfo(const std::string & username){


    cout<<"Try to get "<<username<<"'s public infomation."<<endl;

    bool ok = true;
    // QSqlQuery q;

    // std::string str= "select password from user where username='"+username+"'";

    // QString sql=QString::fromStdString(str) ;
    // QString qPw = QString::fromStdString(pwd);
    //  q.exec(sql);
    //  if(q.next()){
    //      QString dbPwd = q.value(0).toString();

    //      if(!dbPwd.isEmpty() && dbPwd.compare(qPw,Qt::CaseInsensitive) == 0){
    //         ok = true;
    //      }

    //  }

    //  cout<<"login result="<<ok<<endl;
     return ok;
}


User Database::getUser(const std::string& userName){

    User user;

    //TODO 在这里查询和填充用户信息.

    return user;

}



shared_ptr<Database> DBHelper::  db =  shared_ptr<Database>(new Database());

shared_ptr<Database> DBHelper:: getDatabase() {
    return db;
}
