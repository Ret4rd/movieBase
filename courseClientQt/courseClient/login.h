#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QCryptographicHash>
#include "registration.h"
#include "QtSql/QSqlDatabase"
#include "account.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    //Registration regWin;
    Account myAc;
    QSqlDatabase db;
    //QWidget *parent;
    static QString getMd5(QString source);

public slots:
    void on_Login_destroyed();
private slots:


    void on_btReg_clicked();

    void on_btLogin_clicked();

    //void on_Login_destroyed();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
