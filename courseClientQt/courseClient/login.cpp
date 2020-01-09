#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlError"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Авторизация");
    ui->lePassword->setEchoMode(QLineEdit::Password);
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL SERVER};SERVER=LAPTOP-0R0CFR1B;DATABASE=courseWork;Trusted_Connection=yes;");
    if(!db.open())
           QMessageBox::warning(0,"Ошибка", "Не удалось подключиться к базе данных");
}

Login::~Login()
{
    delete ui;
}

void Login::on_btReg_clicked()
{
    Registration *regWin = new Registration;
    regWin->show();
}

void Login::on_btLogin_clicked()
{
    if(ui->leLogin->text() != "" && ui->lePassword->text() != "")
    {
        QSqlQuery query;
        query.prepare("{call loginAccount(?, ?)}");
        query.bindValue(0,  ui->leLogin->text());
        query.bindValue(1, getMd5(ui->lePassword->text()));
        query.exec();
        query.next();
        int myId = query.value(0).toInt();
        if(myId == 0)
            QMessageBox::warning(0,"Ошибка", "Неверный логин или пароль");
        else
        {
            MainWindow *mWin = new MainWindow;
            mWin->setDb(db);
            mWin->setMinAccount(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                                ui->lePassword->text(), query);
            mWin->show();
            this->close();
        }
    }
    else
        QMessageBox::warning(0,"Ошибка", "Заполните поля");
}

void Login::on_Login_destroyed()
{

}

QString Login::getMd5(QString source)
{
    QCryptographicHash md5(QCryptographicHash::Md5);
    md5.addData(source.toUtf8());
    return md5.result().toHex().constData();
}
