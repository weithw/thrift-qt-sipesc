#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include <iostream>

#include "globals.h"

using namespace org::ssdut::sipesc::network::service;
using namespace org::ssdut::sipesc::network::types;

using boost::shared_ptr;
using namespace std;
using namespace apache::thrift;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();


private slots:
    void on_loginPushButton_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
