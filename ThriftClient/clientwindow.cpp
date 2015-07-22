#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);

    stringListModel= new QStringListModel();

    stringListModel->setStringList(srcfiles);

    ui->filesListView->setModel(stringListModel);

    commandPaser = new CommandParser();

    connect(commandPaser,SIGNAL(updateStatus(QString)),this,SLOT(onUpdateStatus(QString)));

}

ClientWindow::~ClientWindow()
{
    delete ui;
    if(stringListModel != NULL){
        delete stringListModel;
        stringListModel = NULL;
    }

    delete commandPaser;
}


void ClientWindow::on_submitButton_clicked()
{

    QString command = ui->commandLineEdit->text();

    if(command.isNull() || command.isEmpty()){
        QMessageBox::warning(this, tr("Error"), tr("Command value cannot be empty.\n"));
        return;
    }

    if(commandPaser != NULL){
        try {
           //调用客户端的命令解析
          commandPaser->parse(command);
        }catch (SipescException ex){
           onUpdateStatus(tr("Exception catched.\n"));
        }
    }
    else {
        QMessageBox::warning(this, tr("Error"), tr("Cannot conncect to host.\n"));
        return;
    }

}

void ClientWindow::on_addFileButton_clicked()
{


    QString file = QFileDialog::getOpenFileName(this);
    if(!file.isNull() && !file.isEmpty()){
        srcfiles.append(file);
        stringListModel->setStringList(srcfiles);
    }

}

void ClientWindow::on_clearfilesButton_clicked()
{
    srcfiles.clear();
    stringListModel->setStringList(srcfiles);
}

void ClientWindow::on_sendFilesButton_clicked()
{
    if(Globals:: networkService == NULL){
        onUpdateStatus(tr("Error: Service Client not set yet.\n"));
        return;
    }

    onUpdateStatus(tr("ok ok\n "));



    qint64  MAX_BUFFER_SIZE = 16*1024*1024;//发送文件大小限制16M。
    char* buffer = new char[MAX_BUFFER_SIZE];



    for(int i = 0, size = srcfiles.size();i < size; ++i){

        QString & fileString = srcfiles[i];
        QFile* sourceFile = new QFile(fileString);

        if(!sourceFile->open(QIODevice::ReadOnly)){

            onUpdateStatus( tr("[Sender] Fail to open %1: \n %2\n").arg(fileString).arg(sourceFile->errorString()));

            delete sourceFile;

            continue;
        }

       qint64 totalSize = sourceFile->size();

       if(totalSize >= MAX_BUFFER_SIZE){

           onUpdateStatus( tr("[Sender]File too large %1: \n").arg(fileString));

           delete sourceFile;

           continue;
       }

        org::ssdut::sipesc::network::types::Data data;

        data.size = sourceFile->read(buffer,totalSize);

       // data.content.assign(buffer,data.size);

        data.content.assign(buffer,data.size);

        int last = fileString.lastIndexOf('/');
        if(last == -1){
            last = fileString.lastIndexOf('\\');
        }

        QString fileName = fileString.right(fileString.size() -  last - 1);

        //TODO FIXME the token.
         int64_t uploadedSize = Globals::networkService->uploadFile(Globals::authResult.authenticationToken, std::string(fileName.toUtf8().constData()), data.size,data.content);

       cout<<"file size:"<<totalSize<<",readed file size:"<<data.size<<endl;

       if(uploadedSize == totalSize){
           onUpdateStatus( tr("[Sender] File:\"%1\"  has been sent successfully! \n ").arg(fileString));
       }else{
           onUpdateStatus( tr("[Sender] Some error happen when uploading %1. \n ").arg(fileString));
       }

       sourceFile->close();

        delete sourceFile;

    }

    delete buffer;

}

void  ClientWindow::onUpdateStatus(QString message){

    ui->messageTextEdit->insertPlainText(message);
    //ui->messageTextEdit->insertPlainText("\n");
    ui->messageTextEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
}

void ClientWindow::on_removeFileButton_clicked()
{
    int row = ui->filesListView->currentIndex().row();
    stringListModel->removeRow(row);
    srcfiles.removeAt(row);

}
