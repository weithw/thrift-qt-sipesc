/********************************************************************************
** Form generated from reading UI file 'registdialog.ui'
**
** Created: Wed Jul 22 09:56:54 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTDIALOG_H
#define UI_REGISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *commentsLabel;
    QTextEdit *commentsTextEdit;
    QLabel *privilegeLevelLabel;
    QComboBox *privilegeLevelComboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLable;
    QLineEdit *nameLineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *repeatPwdLable;
    QLineEdit *repeatPwdLineEdit;

    void setupUi(QDialog *RegistDialog)
    {
        if (RegistDialog->objectName().isEmpty())
            RegistDialog->setObjectName(QString::fromUtf8("RegistDialog"));
        RegistDialog->resize(519, 390);
        buttonBox = new QDialogButtonBox(RegistDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(120, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        commentsLabel = new QLabel(RegistDialog);
        commentsLabel->setObjectName(QString::fromUtf8("commentsLabel"));
        commentsLabel->setGeometry(QRect(30, 230, 61, 16));
        commentsTextEdit = new QTextEdit(RegistDialog);
        commentsTextEdit->setObjectName(QString::fromUtf8("commentsTextEdit"));
        commentsTextEdit->setGeometry(QRect(100, 230, 251, 81));
        privilegeLevelLabel = new QLabel(RegistDialog);
        privilegeLevelLabel->setObjectName(QString::fromUtf8("privilegeLevelLabel"));
        privilegeLevelLabel->setGeometry(QRect(30, 170, 54, 15));
        privilegeLevelComboBox = new QComboBox(RegistDialog);
        privilegeLevelComboBox->setObjectName(QString::fromUtf8("privilegeLevelComboBox"));
        privilegeLevelComboBox->setGeometry(QRect(100, 170, 251, 21));
        layoutWidget = new QWidget(RegistDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 321, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userNameLabel = new QLabel(layoutWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        horizontalLayout->addWidget(userNameLabel);

        userNameLineEdit = new QLineEdit(layoutWidget);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        horizontalLayout->addWidget(userNameLineEdit);

        layoutWidget1 = new QWidget(RegistDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 100, 321, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        emailLabel = new QLabel(layoutWidget1);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        horizontalLayout_2->addWidget(emailLabel);

        emailLineEdit = new QLineEdit(layoutWidget1);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

        horizontalLayout_2->addWidget(emailLineEdit);

        layoutWidget2 = new QWidget(RegistDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 130, 321, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        nameLable = new QLabel(layoutWidget2);
        nameLable->setObjectName(QString::fromUtf8("nameLable"));

        horizontalLayout_3->addWidget(nameLable);

        nameLineEdit = new QLineEdit(layoutWidget2);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        horizontalLayout_3->addWidget(nameLineEdit);

        layoutWidget3 = new QWidget(RegistDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 190, 321, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        addressLabel = new QLabel(layoutWidget3);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        horizontalLayout_5->addWidget(addressLabel);

        addressLineEdit = new QLineEdit(layoutWidget3);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        horizontalLayout_5->addWidget(addressLineEdit);

        layoutWidget4 = new QWidget(RegistDialog);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 40, 321, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        passwordLabel = new QLabel(layoutWidget4);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        horizontalLayout_4->addWidget(passwordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget4);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(passwordLineEdit);

        layoutWidget5 = new QWidget(RegistDialog);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 70, 321, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        repeatPwdLable = new QLabel(layoutWidget5);
        repeatPwdLable->setObjectName(QString::fromUtf8("repeatPwdLable"));

        horizontalLayout_6->addWidget(repeatPwdLable);

        repeatPwdLineEdit = new QLineEdit(layoutWidget5);
        repeatPwdLineEdit->setObjectName(QString::fromUtf8("repeatPwdLineEdit"));
        repeatPwdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(repeatPwdLineEdit);


        retranslateUi(RegistDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RegistDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RegistDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RegistDialog);
    } // setupUi

    void retranslateUi(QDialog *RegistDialog)
    {
        RegistDialog->setWindowTitle(QApplication::translate("RegistDialog", "Regist", 0, QApplication::UnicodeUTF8));
        commentsLabel->setText(QApplication::translate("RegistDialog", "comments:", 0, QApplication::UnicodeUTF8));
        privilegeLevelLabel->setText(QApplication::translate("RegistDialog", "level:", 0, QApplication::UnicodeUTF8));
        privilegeLevelComboBox->clear();
        privilegeLevelComboBox->insertItems(0, QStringList()
         << QApplication::translate("RegistDialog", "normal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegistDialog", "manager", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegistDialog", "admin", 0, QApplication::UnicodeUTF8)
        );
        userNameLabel->setText(QApplication::translate("RegistDialog", "userName:", 0, QApplication::UnicodeUTF8));
        emailLabel->setText(QApplication::translate("RegistDialog", "email:          ", 0, QApplication::UnicodeUTF8));
        nameLable->setText(QApplication::translate("RegistDialog", "name:          ", 0, QApplication::UnicodeUTF8));
        addressLabel->setText(QApplication::translate("RegistDialog", "address:      ", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("RegistDialog", "password:  ", 0, QApplication::UnicodeUTF8));
        repeatPwdLable->setText(QApplication::translate("RegistDialog", "repeatPwd:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegistDialog: public Ui_RegistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTDIALOG_H
