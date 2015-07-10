#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

#include <thrift/Thrift.h>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginPushButton_clicked()
{
    if(ui->userNameLineEdit->text().isEmpty() || ui->passwordLineEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("Warn"), tr("Fill out the values.\n"));
        return;
    }


    try{
    AuthenticationResult authResult;


    std::string username = ui->userNameLineEdit->text().toUtf8().constData();

    std::string password = ui->passwordLineEdit->text().toUtf8().constData();

    ui->userNameLineEdit->setText(QString::fromUtf8(username.data(),username.size()));
    cout<<"Try to login:"<<username<<","<<password<<endl;


    Globals::networkService->login(authResult,username,password);

    cout <<" Authenticate Ok, and token is:"<< authResult.authenticationToken<<endl;
    QMessageBox::information(this, tr("Info"), tr("login ok.\n"));
    Globals::authResult = authResult;

    accept();
    }catch(SipescException & ex){
        cout<<ex.errorCode<<","<<ex.why;
      QMessageBox::information(this, tr("Info"), tr("login Fail.\n"));
    }
    catch(TException tx){
          cout << "ERROR: " << tx.what() << endl;
    }

}
