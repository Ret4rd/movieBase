#include "registration.h"
#include "ui_registration.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QMessageBox>
#include <QDebug>
#include "QSqlError"

Registration::Registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    ui->lePassword->setEchoMode(QLineEdit::Password);
    setWindowTitle("Регистрация");

}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_btReg_clicked()
{

    if(ui->leName->text() != "" && ui->leLogin->text() != "" && ui->lePassword->text() != "")
    {
        QSqlQuery query;
        query.prepare("{call regAccount(?, ?, ?, ?)}");
        query.bindValue(0, ui->leName->text());
        query.bindValue(1, ui->leSecName->text());
        query.bindValue(2,  ui->leLogin->text());
        query.bindValue(3, Login::getMd5(ui->lePassword->text()));
        query.exec();
        query.next();
        int myId = query.value(0).toInt();
        if(myId == 0)
            QMessageBox::warning(0,"Ошибка", query.lastError().text());
        else
        {
            QMessageBox accMes;
            accMes.setText("Вы успешно создали аккаунт");
            accMes.exec();
            this->close();
        }
    }
    else
        QMessageBox::warning(0,"Ошибка", "Заполните поля с *");
}
