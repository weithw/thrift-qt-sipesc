/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created: Thu Jul 16 11:04:05 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *commandLabel;
    QLineEdit *commandLineEdit;
    QPushButton *submitButton;
    QLabel *attachmentLlabel;
    QHBoxLayout *horizontalLayout_3;
    QListView *filesListView;
    QVBoxLayout *verticalLayout;
    QPushButton *addFileButton;
    QPushButton *removeFileButton;
    QPushButton *clearfilesButton;
    QPushButton *sendFilesButton;
    QTextEdit *messageTextEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClientWindow)
    {
        if (ClientWindow->objectName().isEmpty())
            ClientWindow->setObjectName(QString::fromUtf8("ClientWindow"));
        ClientWindow->resize(400, 326);
        centralWidget = new QWidget(ClientWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        commandLabel = new QLabel(centralWidget);
        commandLabel->setObjectName(QString::fromUtf8("commandLabel"));

        horizontalLayout_2->addWidget(commandLabel);

        commandLineEdit = new QLineEdit(centralWidget);
        commandLineEdit->setObjectName(QString::fromUtf8("commandLineEdit"));

        horizontalLayout_2->addWidget(commandLineEdit);

        submitButton = new QPushButton(centralWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        horizontalLayout_2->addWidget(submitButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        attachmentLlabel = new QLabel(centralWidget);
        attachmentLlabel->setObjectName(QString::fromUtf8("attachmentLlabel"));

        verticalLayout_2->addWidget(attachmentLlabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        filesListView = new QListView(centralWidget);
        filesListView->setObjectName(QString::fromUtf8("filesListView"));

        horizontalLayout_3->addWidget(filesListView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addFileButton = new QPushButton(centralWidget);
        addFileButton->setObjectName(QString::fromUtf8("addFileButton"));

        verticalLayout->addWidget(addFileButton);

        removeFileButton = new QPushButton(centralWidget);
        removeFileButton->setObjectName(QString::fromUtf8("removeFileButton"));

        verticalLayout->addWidget(removeFileButton);

        clearfilesButton = new QPushButton(centralWidget);
        clearfilesButton->setObjectName(QString::fromUtf8("clearfilesButton"));

        verticalLayout->addWidget(clearfilesButton);

        sendFilesButton = new QPushButton(centralWidget);
        sendFilesButton->setObjectName(QString::fromUtf8("sendFilesButton"));

        verticalLayout->addWidget(sendFilesButton);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_3);

        messageTextEdit = new QTextEdit(centralWidget);
        messageTextEdit->setObjectName(QString::fromUtf8("messageTextEdit"));
        messageTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(messageTextEdit);

        ClientWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ClientWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        ClientWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClientWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClientWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ClientWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClientWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        commandLabel->setBuddy(commandLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ClientWindow);

        QMetaObject::connectSlotsByName(ClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ClientWindow)
    {
        ClientWindow->setWindowTitle(QApplication::translate("ClientWindow", "Client", 0, QApplication::UnicodeUTF8));
        commandLabel->setText(QApplication::translate("ClientWindow", "&Command:", 0, QApplication::UnicodeUTF8));
        submitButton->setText(QApplication::translate("ClientWindow", "&Execute", 0, QApplication::UnicodeUTF8));
        attachmentLlabel->setText(QApplication::translate("ClientWindow", "Attachment:", 0, QApplication::UnicodeUTF8));
        addFileButton->setText(QApplication::translate("ClientWindow", "&Add", 0, QApplication::UnicodeUTF8));
        removeFileButton->setText(QApplication::translate("ClientWindow", "&Remove", 0, QApplication::UnicodeUTF8));
        clearfilesButton->setText(QApplication::translate("ClientWindow", "&Clear", 0, QApplication::UnicodeUTF8));
        sendFilesButton->setText(QApplication::translate("ClientWindow", "&Send", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClientWindow: public Ui_ClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
