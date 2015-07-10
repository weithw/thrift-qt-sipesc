#ifndef USER_H
#define USER_H

#include <QObject>

#include <QString>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = 0);
    

    QString username;
    QString token;
    qint32 userId;

signals:
    
public slots:
    
};

#endif // USER_H
