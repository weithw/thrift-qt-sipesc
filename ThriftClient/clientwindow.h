#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStandardItem>
#include <QtGui>


#include <iostream>

#include "commandparser.h"
#include "globals.h"



#include <thrift/Thrift.h>


using namespace org::ssdut::sipesc::network::types;
using namespace org::ssdut::sipesc::network::service;

using boost::shared_ptr;
using namespace std;
using namespace apache::thrift;


namespace Ui {
class ClientWindow;
}

class ClientWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();
    
private slots:
    void on_submitButton_clicked();

    void on_addFileButton_clicked();

    void on_clearfilesButton_clicked();

    void on_sendFilesButton_clicked();

     void onUpdateStatus(QString);
     void on_removeFileButton_clicked();

private:
    Ui::ClientWindow *ui;
    QStringListModel* stringListModel; //声明model
    QStringList srcfiles;
    CommandParser* commandPaser;
};

#endif // CLIENTWINDOW_H
