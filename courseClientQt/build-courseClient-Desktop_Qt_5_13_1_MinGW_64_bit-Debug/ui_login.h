/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QPushButton *btReg;
    QLineEdit *leLogin;
    QPushButton *btLogin;
    QLabel *lPassword;
    QLineEdit *lePassword;
    QLabel *lLogin;
    QLabel *lWelcome;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(285, 367);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btReg = new QPushButton(Login);
        btReg->setObjectName(QString::fromUtf8("btReg"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        btReg->setFont(font);

        gridLayout->addWidget(btReg, 6, 0, 1, 1);

        leLogin = new QLineEdit(Login);
        leLogin->setObjectName(QString::fromUtf8("leLogin"));
        leLogin->setFont(font);
        leLogin->setAlignment(Qt::AlignCenter);
        leLogin->setClearButtonEnabled(false);

        gridLayout->addWidget(leLogin, 2, 0, 1, 1);

        btLogin = new QPushButton(Login);
        btLogin->setObjectName(QString::fromUtf8("btLogin"));
        btLogin->setFont(font);

        gridLayout->addWidget(btLogin, 5, 0, 1, 1);

        lPassword = new QLabel(Login);
        lPassword->setObjectName(QString::fromUtf8("lPassword"));
        lPassword->setFont(font);
        lPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lPassword, 3, 0, 1, 1);

        lePassword = new QLineEdit(Login);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setFont(font);
        lePassword->setAlignment(Qt::AlignCenter);
        lePassword->setDragEnabled(false);
        lePassword->setClearButtonEnabled(false);

        gridLayout->addWidget(lePassword, 4, 0, 1, 1);

        lLogin = new QLabel(Login);
        lLogin->setObjectName(QString::fromUtf8("lLogin"));
        lLogin->setFont(font);
        lLogin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lLogin, 1, 0, 1, 1);

        lWelcome = new QLabel(Login);
        lWelcome->setObjectName(QString::fromUtf8("lWelcome"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lWelcome->setFont(font1);
        lWelcome->setTextFormat(Qt::AutoText);
        lWelcome->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lWelcome, 0, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        btReg->setText(QCoreApplication::translate("Login", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        leLogin->setText(QString());
        btLogin->setText(QCoreApplication::translate("Login", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        lPassword->setText(QCoreApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        lePassword->setText(QString());
        lLogin->setText(QCoreApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        lWelcome->setText(QCoreApplication::translate("Login", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\320\270 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\262\321\205\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
