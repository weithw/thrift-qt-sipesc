#include "database.h"
#include <string>
#include <time.h>
#include <stdio.h>
#include <qdir.h>
Database::Database()
{

    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    create();
}

void Database::create(){

    if(!db.open()){
        cout<<"not open"<<endl;
        return;
    }

    QSqlQuery query;
    if(query.exec("create table user (id integer primary key ,username varchar(20),password varchar(80),name varchar(20),privilegeLevel int,createdTime integer,address varchar(80),comments varchar(80))"))

    query.exec("insert into user values(4,'kate','123','snow',1,0,'ssdut','commets')");
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

QString Database::getUsernameById(int id) {
    QSqlQuery q;

    QString sql = QString("select username from user where id='")+QString::number(id, 10)+QString("'");
    q.exec(sql);
    if(q.next()){
        QString username = q.value(0).toString();
        cout << "username is:" << username.toLatin1().data() << endl;
        return username;

     }

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

User Database::getUser(const std::string& userName){
//TODO 在这里查询和填充用户信息.
    User user;
    QSqlQuery q;
    std::string str= "select * from user where username='"+userName+"'";
    QString sql=QString::fromStdString(str) ;
    q.exec(sql);
    if(q.next()){

        int dbID = q.value(0).toInt();
        if(dbID!=0)
            user.__set_id(dbID);

       QString dbUserName=q.value(1).toString();
       if(!dbUserName.isEmpty())
           user.__set_userName(dbUserName.toStdString());

      QString dbName=q.value(3).toString();
       if(!dbName.isEmpty())
           user.__set_name(dbName.toStdString());

       int dbPrivilege=q.value(4).toInt();
       if(dbPrivilege!=0){
           if(dbPrivilege==1)
            user.__set_privilege(org::ssdut::sipesc::network::types::PrivilegeLevel::NORMAL);
           else if(dbPrivilege==3)
               user.__set_privilege(org::ssdut::sipesc::network::types::PrivilegeLevel::MANAGER);
           else if(dbPrivilege==5)
               user.__set_privilege(org::ssdut::sipesc::network::types::PrivilegeLevel::ADMIN);
       }

       QString dbCreatedTime=q.value(5).toString();
       if(!dbCreatedTime.isEmpty())
           user.__set_created((org::ssdut::sipesc::network::types::Timestamp)dbCreatedTime.toLong());

       QString dbAddress=q.value(6).toString();
       if(!dbAddress.isEmpty())
           user.__set_address(dbAddress.toStdString());


       QString dbComments=q.value(7).toString();
       if(!dbComments.isEmpty())
           user.__set_comments((org::ssdut::sipesc::network::types::Text)dbComments.toStdString());

    }

    return user;

}
bool Database::regist(const User& newUser, const std::string& password){
    bool registResult=false;
    if(!db.open()){
        cout<<"db not open"<<endl;
        return registResult;
    }
    QSqlQuery q;
    std::string str= "select ID from user where username='"+newUser.userName+"'";
    QString sql=QString::fromStdString(str) ;
    q.exec(sql);
    if(!q.next()){
        cout<<"username avaliable"<<endl;
        /* str="select * from user";
        sql=QString::fromStdString(str) ;
        q.exec(sql);
        if(q.next())
          int totlecount=

        string ID=q.value(0).toString().toStdString();
        cout<<ID<<endl;*/
        string pri;
        if(newUser.privilege==org::ssdut::sipesc::network::types::PrivilegeLevel::NORMAL)
            pri="1";
        else if(newUser.privilege==org::ssdut::sipesc::network::types::PrivilegeLevel::MANAGER)
            pri="3";
        else if(newUser.privilege==org::ssdut::sipesc::network::types::PrivilegeLevel::ADMIN)
            pri="5";

        org::ssdut::sipesc::network::types::Timestamp t = time(0);
        QString qtmp;
        qtmp.setNum(t);
        string tmp=qtmp.toStdString();

        str="insert into user values(null,'" +newUser.userName+"','"+password+"','" +newUser.name+"'," +pri+","+tmp+",'"+newUser.address+"','"+newUser.comments+"')";

        cout<<str;
        sql=QString::fromStdString(str);
        q.clear();
        if(q.exec(sql)){

            cout<<"insert done"<<endl;
            registResult=true;

//make new directory for new user
            QDir dir;
            QString dir_path= QString("user/") +  QString(QString::fromLocal8Bit(newUser.userName.c_str()));             
            dir.mkdir(dir_path);
        }
        else 
            cout<<"insert fail"<<endl;
    }
    else      
        cout<<"username not avaliable"<<endl;
    return registResult;
}



shared_ptr<Database> DBHelper::  db =  shared_ptr<Database>(new Database());

shared_ptr<Database> DBHelper:: getDatabase() {
    return db;
}
