/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created: Wed Jul 22 10:06:10 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginPushButton;
    QPushButton *resetPushButton;
    QPushButton *registPushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPassword;
    QLineEdit *passwordLineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelUserName;
    QLineEdit *userNameLineEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(390, 190);
        layoutWidget = new QWidget(LoginDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 110, 217, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        loginPushButton = new QPushButton(layoutWidget);
        loginPushButton->setObjectName(QString::fromUtf8("loginPushButton"));

        horizontalLayout->addWidget(loginPushButton);

        resetPushButton = new QPushButton(layoutWidget);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));

        horizontalLayout->addWidget(resetPushButton);

        registPushButton = new QPushButton(layoutWidget);
        registPushButton->setObjectName(QString::fromUtf8("registPushButton"));

        horizontalLayout->addWidget(registPushButton);

        layoutWidget1 = new QWidget(LoginDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 66, 181, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelPassword = new QLabel(layoutWidget1);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        horizontalLayout_3->addWidget(labelPassword);

        passwordLineEdit = new QLineEdit(layoutWidget1);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        horizontalLayout_3->addWidget(passwordLineEdit);

        layoutWidget2 = new QWidget(LoginDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(90, 40, 181, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelUserName = new QLabel(layoutWidget2);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));

        horizontalLayout_2->addWidget(labelUserName);

        userNameLineEdit = new QLineEdit(layoutWidget2);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        horizontalLayout_2->addWidget(userNameLineEdit);

#ifndef QT_NO_SHORTCUT
        labelPassword->setBuddy(passwordLineEdit);
        labelUserName->setBuddy(userNameLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", 0, QApplication::UnicodeUTF8));
        loginPushButton->setText(QApplication::translate("LoginDialog", "&Login", 0, QApplication::UnicodeUTF8));
        resetPushButton->setText(QApplication::translate("LoginDialog", "&Reset", 0, QApplication::UnicodeUTF8));
        registPushButton->setText(QApplication::translate("LoginDialog", "Regist", 0, QApplication::UnicodeUTF8));
        labelPassword->setText(QApplication::translate("LoginDialog", "&Password:", 0, QApplication::UnicodeUTF8));
        labelUserName->setText(QApplication::translate("LoginDialog", "&User Name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
