/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGridLayout *gridLayout;
    QLabel *lLogin;
    QLineEdit *leName;
    QLineEdit *lePassword;
    QLabel *lSecName;
    QLabel *lPassword;
    QLineEdit *leSecName;
    QLineEdit *leLogin;
    QLabel *lName;
    QPushButton *btReg;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(286, 370);
        gridLayout = new QGridLayout(Registration);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lLogin = new QLabel(Registration);
        lLogin->setObjectName(QString::fromUtf8("lLogin"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        lLogin->setFont(font);
        lLogin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lLogin, 4, 0, 1, 1);

        leName = new QLineEdit(Registration);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setFont(font);
        leName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leName, 1, 0, 1, 1);

        lePassword = new QLineEdit(Registration);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setFont(font);
        lePassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lePassword, 7, 0, 1, 1);

        lSecName = new QLabel(Registration);
        lSecName->setObjectName(QString::fromUtf8("lSecName"));
        lSecName->setFont(font);
        lSecName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lSecName, 2, 0, 1, 1);

        lPassword = new QLabel(Registration);
        lPassword->setObjectName(QString::fromUtf8("lPassword"));
        lPassword->setFont(font);
        lPassword->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lPassword, 6, 0, 1, 1);

        leSecName = new QLineEdit(Registration);
        leSecName->setObjectName(QString::fromUtf8("leSecName"));
        leSecName->setFont(font);
        leSecName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leSecName, 3, 0, 1, 1);

        leLogin = new QLineEdit(Registration);
        leLogin->setObjectName(QString::fromUtf8("leLogin"));
        leLogin->setFont(font);
        leLogin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(leLogin, 5, 0, 1, 1);

        lName = new QLabel(Registration);
        lName->setObjectName(QString::fromUtf8("lName"));
        lName->setFont(font);
        lName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lName, 0, 0, 1, 1);

        btReg = new QPushButton(Registration);
        btReg->setObjectName(QString::fromUtf8("btReg"));
        btReg->setFont(font);

        gridLayout->addWidget(btReg, 8, 0, 1, 1);


        retranslateUi(Registration);

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        lLogin->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275*", nullptr));
        lSecName->setText(QCoreApplication::translate("Registration", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        lPassword->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214*", nullptr));
        lName->setText(QCoreApplication::translate("Registration", "\320\230\320\274\321\217*", nullptr));
        btReg->setText(QCoreApplication::translate("Registration", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
