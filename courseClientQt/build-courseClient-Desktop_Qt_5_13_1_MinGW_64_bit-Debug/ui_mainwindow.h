/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Account;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAccount;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *tab0Layout;
    QVBoxLayout *favLayout;
    QLabel *lFavMovie;
    QLabel *lSetFavMovie;
    QLabel *lFavActor;
    QLabel *lSetFavActor;
    QLabel *lFavDirector;
    QLabel *lSetFavDirector;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *infLayout;
    QLabel *lName;
    QLineEdit *leName;
    QLabel *lSecName;
    QLineEdit *leSecName;
    QLabel *lLogin;
    QLineEdit *leLogin;
    QLabel *lPassword;
    QLineEdit *lePassword;
    QPushButton *btChange;
    QPushButton *btOk;
    QWidget *tabMovie;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lSearch;
    QLineEdit *leSearch;
    QPushButton *btSearch;
    QVBoxLayout *verticalLayout_2;
    QLabel *lFind;
    QLabel *lMyMovie;
    QLabel *lDirector;
    QLabel *lFindDirector;
    QLabel *lActors;
    QLabel *lFindActors;
    QLabel *lRating;
    QLabel *lFindRating;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btFavMovie;
    QPushButton *btSetRating;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(631, 491);
        Account = new QAction(MainWindow);
        Account->setObjectName(QString::fromUtf8("Account"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabAccount = new QWidget();
        tabAccount->setObjectName(QString::fromUtf8("tabAccount"));
        verticalLayout_3 = new QVBoxLayout(tabAccount);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tab0Layout = new QHBoxLayout();
        tab0Layout->setObjectName(QString::fromUtf8("tab0Layout"));
        favLayout = new QVBoxLayout();
        favLayout->setObjectName(QString::fromUtf8("favLayout"));
        lFavMovie = new QLabel(tabAccount);
        lFavMovie->setObjectName(QString::fromUtf8("lFavMovie"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        lFavMovie->setFont(font);

        favLayout->addWidget(lFavMovie);

        lSetFavMovie = new QLabel(tabAccount);
        lSetFavMovie->setObjectName(QString::fromUtf8("lSetFavMovie"));
        lSetFavMovie->setFont(font);

        favLayout->addWidget(lSetFavMovie);

        lFavActor = new QLabel(tabAccount);
        lFavActor->setObjectName(QString::fromUtf8("lFavActor"));
        lFavActor->setFont(font);

        favLayout->addWidget(lFavActor);

        lSetFavActor = new QLabel(tabAccount);
        lSetFavActor->setObjectName(QString::fromUtf8("lSetFavActor"));
        lSetFavActor->setFont(font);

        favLayout->addWidget(lSetFavActor);

        lFavDirector = new QLabel(tabAccount);
        lFavDirector->setObjectName(QString::fromUtf8("lFavDirector"));
        lFavDirector->setFont(font);

        favLayout->addWidget(lFavDirector);

        lSetFavDirector = new QLabel(tabAccount);
        lSetFavDirector->setObjectName(QString::fromUtf8("lSetFavDirector"));
        lSetFavDirector->setFont(font);

        favLayout->addWidget(lSetFavDirector);


        tab0Layout->addLayout(favLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab0Layout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab0Layout->addItem(verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab0Layout->addItem(verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab0Layout->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab0Layout->addItem(verticalSpacer_5);

        infLayout = new QVBoxLayout();
        infLayout->setObjectName(QString::fromUtf8("infLayout"));
        lName = new QLabel(tabAccount);
        lName->setObjectName(QString::fromUtf8("lName"));
        lName->setFont(font);

        infLayout->addWidget(lName);

        leName = new QLineEdit(tabAccount);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setFont(font);

        infLayout->addWidget(leName);

        lSecName = new QLabel(tabAccount);
        lSecName->setObjectName(QString::fromUtf8("lSecName"));
        lSecName->setFont(font);

        infLayout->addWidget(lSecName);

        leSecName = new QLineEdit(tabAccount);
        leSecName->setObjectName(QString::fromUtf8("leSecName"));
        leSecName->setFont(font);

        infLayout->addWidget(leSecName);

        lLogin = new QLabel(tabAccount);
        lLogin->setObjectName(QString::fromUtf8("lLogin"));
        lLogin->setFont(font);

        infLayout->addWidget(lLogin);

        leLogin = new QLineEdit(tabAccount);
        leLogin->setObjectName(QString::fromUtf8("leLogin"));
        leLogin->setFont(font);

        infLayout->addWidget(leLogin);

        lPassword = new QLabel(tabAccount);
        lPassword->setObjectName(QString::fromUtf8("lPassword"));
        lPassword->setFont(font);

        infLayout->addWidget(lPassword);

        lePassword = new QLineEdit(tabAccount);
        lePassword->setObjectName(QString::fromUtf8("lePassword"));
        lePassword->setFont(font);

        infLayout->addWidget(lePassword);

        btChange = new QPushButton(tabAccount);
        btChange->setObjectName(QString::fromUtf8("btChange"));
        btChange->setFont(font);

        infLayout->addWidget(btChange);

        btOk = new QPushButton(tabAccount);
        btOk->setObjectName(QString::fromUtf8("btOk"));
        btOk->setEnabled(true);
        btOk->setFont(font);

        infLayout->addWidget(btOk);


        tab0Layout->addLayout(infLayout);


        verticalLayout_3->addLayout(tab0Layout);

        tabWidget->addTab(tabAccount, QString());
        tabMovie = new QWidget();
        tabMovie->setObjectName(QString::fromUtf8("tabMovie"));
        tabWidget->addTab(tabMovie, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lSearch = new QLabel(tab_4);
        lSearch->setObjectName(QString::fromUtf8("lSearch"));
        lSearch->setFont(font);

        horizontalLayout->addWidget(lSearch);

        leSearch = new QLineEdit(tab_4);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));
        leSearch->setFont(font);

        horizontalLayout->addWidget(leSearch);

        btSearch = new QPushButton(tab_4);
        btSearch->setObjectName(QString::fromUtf8("btSearch"));
        btSearch->setFont(font);

        horizontalLayout->addWidget(btSearch);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lFind = new QLabel(tab_4);
        lFind->setObjectName(QString::fromUtf8("lFind"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(16);
        lFind->setFont(font1);

        verticalLayout_2->addWidget(lFind, 0, Qt::AlignHCenter);

        lMyMovie = new QLabel(tab_4);
        lMyMovie->setObjectName(QString::fromUtf8("lMyMovie"));
        lMyMovie->setFont(font1);

        verticalLayout_2->addWidget(lMyMovie);

        lDirector = new QLabel(tab_4);
        lDirector->setObjectName(QString::fromUtf8("lDirector"));
        lDirector->setFont(font1);

        verticalLayout_2->addWidget(lDirector, 0, Qt::AlignHCenter);

        lFindDirector = new QLabel(tab_4);
        lFindDirector->setObjectName(QString::fromUtf8("lFindDirector"));
        lFindDirector->setFont(font1);

        verticalLayout_2->addWidget(lFindDirector);

        lActors = new QLabel(tab_4);
        lActors->setObjectName(QString::fromUtf8("lActors"));
        lActors->setFont(font1);

        verticalLayout_2->addWidget(lActors, 0, Qt::AlignHCenter);

        lFindActors = new QLabel(tab_4);
        lFindActors->setObjectName(QString::fromUtf8("lFindActors"));
        lFindActors->setFont(font1);

        verticalLayout_2->addWidget(lFindActors);

        lRating = new QLabel(tab_4);
        lRating->setObjectName(QString::fromUtf8("lRating"));
        lRating->setFont(font1);

        verticalLayout_2->addWidget(lRating, 0, Qt::AlignHCenter);

        lFindRating = new QLabel(tab_4);
        lFindRating->setObjectName(QString::fromUtf8("lFindRating"));
        lFindRating->setFont(font1);

        verticalLayout_2->addWidget(lFindRating);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btFavMovie = new QPushButton(tab_4);
        btFavMovie->setObjectName(QString::fromUtf8("btFavMovie"));

        horizontalLayout_2->addWidget(btFavMovie);

        btSetRating = new QPushButton(tab_4);
        btSetRating->setObjectName(QString::fromUtf8("btSetRating"));

        horizontalLayout_2->addWidget(btSetRating);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 631, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Account->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        lFavMovie->setText(QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\320\270\320\274\321\213\320\271 \321\204\320\270\320\273\321\214\320\274:", nullptr));
        lSetFavMovie->setText(QString());
        lFavActor->setText(QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\320\270\320\274\321\213\320\271 \320\260\320\272\321\202\320\265\321\200:", nullptr));
        lSetFavActor->setText(QString());
        lFavDirector->setText(QCoreApplication::translate("MainWindow", "\320\233\321\216\320\261\320\270\320\274\321\213\320\271 \321\200\320\265\320\266\320\270\321\201\321\201\320\265\321\200:", nullptr));
        lSetFavDirector->setText(QString());
        lName->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217:", nullptr));
        lSecName->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217:", nullptr));
        lLogin->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        lPassword->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        btChange->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        btOk->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAccount), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMovie), QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\320\274\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\220\320\272\321\202\320\265\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\321\201\321\201\320\265\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\242\320\276\320\277 \321\204\320\270\320\273\321\214\320\274\320\276\320\262", nullptr));
        lSearch->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\321\201\320\272\320\276\320\274\321\213\320\271 \321\204\320\270\320\273\321\214\320\274", nullptr));
        btSearch->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        lFind->setText(QCoreApplication::translate("MainWindow", "\320\222\320\260\321\210 \321\204\320\270\320\273\321\214\320\274:", nullptr));
        lMyMovie->setText(QString());
        lDirector->setText(QCoreApplication::translate("MainWindow", "\320\225\320\263\320\276 \321\201\320\275\320\270\320\274\320\260\320\273:", nullptr));
        lFindDirector->setText(QString());
        lActors->setText(QCoreApplication::translate("MainWindow", "\320\222 \320\275\320\265\320\274 \321\201\320\275\320\270\320\274\320\260\320\273\320\270\321\201\321\214:", nullptr));
        lFindActors->setText(QString());
        lRating->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\321\217\321\217 \320\276\321\206\320\265\320\275\320\272\320\260:", nullptr));
        lFindRating->setText(QString());
        btFavMovie->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\204\320\270\320\273\321\214\320\274 \320\273\321\216\320\261\320\270\320\274\321\213\320\274", nullptr));
        btSetRating->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\276\321\206\320\265\320\275\320\272\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \321\204\320\270\320\273\321\214\320\274\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
