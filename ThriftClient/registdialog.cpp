#include "registdialog.h"
#include "ui_registdialog.h"
#include "globals.h"
#include <QMessageBox>

#include <thrift/Thrift.h>



using namespace org::ssdut::sipesc::network::service;
using namespace org::ssdut::sipesc::network::types;

RegistDialog::RegistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistDialog)
{
    ui->setupUi(this);
}

RegistDialog::~RegistDialog()
{
    delete ui;
}

void RegistDialog::on_buttonBox_accepted()
{
    if(ui->passwordLineEdit->text()!=ui->repeatPwdLineEdit->text()||ui->passwordLineEdit->text().isEmpty())
        QMessageBox::information(this, tr("Info"), tr("password check error.\n"));
    PublicUserInfo temp;
    Globals::networkService->getPublicUserInfo(temp,ui->userNameLineEdit->text().toUtf8().constData());
    if(temp.userId>0)
         QMessageBox::information(this, tr("Info"), tr("userName taken.\n"));
    else{
    User user;
    user.__set_userName( ui->userNameLineEdit->text().toUtf8().constData());
    user.__set_address(ui->addressLineEdit->text().toUtf8().constData());
    user.__set_comments(ui->commentsTextEdit->toPlainText().toStdString());
                          //Incompleted
    user.__set_email(ui->emailLineEdit->text().toUtf8().constData());
    user.__set_name(ui->nameLineEdit->text().toUtf8().constData());
    if(ui->privilegeLevelComboBox->currentIndex()==0)
         user.__set_privilege(PrivilegeLevel::NORMAL);
    else if(ui->privilegeLevelComboBox->currentIndex()==1)
        user.__set_privilege(PrivilegeLevel::MANAGER);
    else if(ui->privilegeLevelComboBox->currentIndex()==2)
        user.__set_privilege(PrivilegeLevel::ADMIN);

    std::string pwd = ui->passwordLineEdit->text().toUtf8().constData();
    bool registOK=Globals::networkService->regist(user,pwd);
    if(registOK)
          QMessageBox::information(this, tr("Info"), tr("regist ok.\n"));
    else
           QMessageBox::information(this, tr("Info"), tr("regist fail.\n"));
    }
}
