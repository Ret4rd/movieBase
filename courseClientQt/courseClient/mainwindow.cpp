#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QMessageBox>
#include <QSqlError>
#include "login.h"
#include "QDebug"
#include "QGroupBox"
#include "QLabel"
#include <QGraphicsView>
#include <QList>
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Ваш аккаунт");
    ui->lePassword->setEchoMode(QLineEdit::Password);
    ui->leName->setReadOnly(1);
    ui->leSecName->setReadOnly(1);
    ui->leLogin->setReadOnly(1);
    //ui->lePassword->setReadOnly(1);
    ui->lePassword->hide();
    ui->lPassword->hide();
    ui->btOk->hide();
    //фильмы
    QVBoxLayout *tabLayout = new QVBoxLayout(ui->tabWidget->widget(1));
    QScrollArea *area = new QScrollArea(ui->tabWidget->widget(1));
    QWidget *base = new QWidget(area);
    area->setWidget(base);
    area->setWidgetResizable(true);
    tabLayout->addWidget(area);
    boxLayout = new QVBoxLayout(base);
    //актеры
    QVBoxLayout *tabLayoutA = new QVBoxLayout(ui->tabWidget->widget(2));
    QScrollArea *areaA = new QScrollArea(ui->tabWidget->widget(2));
    QWidget *baseA = new QWidget(areaA);
    areaA->setWidget(baseA);
    areaA->setWidgetResizable(true);
    tabLayoutA->addWidget(areaA);
    boxLayoutA = new QVBoxLayout(baseA);
    //режиссеры
    QVBoxLayout *tabLayoutD = new QVBoxLayout(ui->tabWidget->widget(3));
    QScrollArea *areaD = new QScrollArea(ui->tabWidget->widget(3));
    QWidget *baseD = new QWidget(areaD);
    areaD->setWidget(baseD);
    areaD->setWidgetResizable(true);
    tabLayoutD->addWidget(areaD);
    boxLayoutD = new QVBoxLayout(baseD);
    //топ фильмов
    QVBoxLayout *tabLayoutR = new QVBoxLayout(ui->tabWidget->widget(4));
    QScrollArea *areaR = new QScrollArea(ui->tabWidget->widget(4));
    QWidget *baseR = new QWidget(areaR);
    areaR->setWidget(baseR);
    areaR->setWidgetResizable(true);
    tabLayoutR->addWidget(areaR);
    boxLayoutR = new QVBoxLayout(baseR);

    connect(ui->btFavMovie, SIGNAL(released()), this, SLOT(on_btFav_clicked()));
    connect(ui->btSetRating, SIGNAL(clicked()), this, SLOT(on_btRating_clicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDb(QSqlDatabase db)
{
    this->db = db;
}

void MainWindow::setMaxAccount(QString id, QString firstName, QString secondName, QString loginClient, QString passwordClient,
                            QString favMovie, QString favDirector, QString favActor)
{
    myAc.id = id;
    myAc.firstName = firstName;
    myAc.secondName = secondName;
    myAc.loginClient = loginClient;
    myAc.passwordClient = passwordClient;
    myAc.favMovie = favMovie;
    myAc.favDirector = favDirector;
    myAc.favActor = favActor;
    ui->leName->setText(firstName);
    ui->leSecName->setText(secondName);
    ui->leLogin->setText(loginClient);
    ui->lePassword->setText(passwordClient);
    ui->lSetFavMovie->setText(favMovie);
    ui->lSetFavDirector->setText(favDirector);
    ui->lSetFavActor->setText(favActor);
}

void MainWindow::setMinAccount(QString id, QString firstName, QString loginClient, QString passwordClient, QSqlQuery query)
{
    myAc.id = id;
    myAc.firstName = firstName;
    myAc.loginClient = loginClient;
    myAc.passwordClient = passwordClient;
    ui->leName->setText(firstName);
    ui->leLogin->setText(loginClient);
    ui->lePassword->setText(passwordClient);
    query.next();
    query.prepare("{call getSecondName(?)}");
    query.bindValue(0, id);
    query.exec();
    query.next();
    ui->leSecName->setText(query.value(0).toString());

    query.next();
    query.prepare("{call getFavMovie(?)}");
    query.bindValue(0, id);
    query.exec();
    query.next();
    ui->lSetFavMovie->setText(query.value(0).toString());

    query.next();
    query.prepare("{call getFavActor(?)}");
    query.bindValue(0, id);
    query.exec();
    query.next();
    ui->lSetFavActor->setText(query.value(0).toString());

    query.next();
    query.prepare("{call getFavDirector(?)}");
    query.bindValue(0, id);
    query.exec();
    query.next();
    ui->lSetFavDirector->setText(query.value(0).toString());
}

void MainWindow::on_btChange_clicked()
{
    ui->leName->setReadOnly(0);
    ui->leSecName->setReadOnly(0);
    //ui->lePassword->setReadOnly(0);
    ui->lePassword->show();
    ui->lPassword->show();
    ui->btOk->show();
}

void MainWindow::on_btOk_clicked()
{
    if(ui->lePassword->text() != "" && ui->leName->text() != "")
    {
        myAc.firstName = ui->leName->text();
        myAc.secondName = ui->leSecName->text();
        myAc.passwordClient = ui->lePassword->text();
        QSqlQuery query;
        query.prepare("{call updateAccount(?, ?, ?, ?)}");
        query.bindValue(0, ui->leName->text());
        query.bindValue(1, ui->leSecName->text());
        query.bindValue(2,  ui->leLogin->text());
        query.bindValue(3, Login::getMd5(ui->lePassword->text()));
        query.exec();
        query.next();
        ui->btOk->hide();
        ui->leName->setReadOnly(1);
        ui->leSecName->setReadOnly(1);
        //ui->lePassword->setReadOnly(1);
        ui->lePassword->hide();
        ui->lPassword->hide();
    }
    else
    {
        QMessageBox accMes;
        accMes.setText("Заполните поле пароля");
        accMes.exec();
    }

}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0)
    {
        QSqlQuery query;
        query.prepare("{call getFavMovie(?)}");
        query.bindValue(0, myAc.id);
        query.exec();
        query.next();
        ui->lSetFavMovie->setText(query.value(0).toString());

        query.next();
        query.prepare("{call getFavActor(?)}");
        query.bindValue(0, myAc.id);
        query.exec();
        query.next();
        ui->lSetFavActor->setText(query.value(0).toString());

        query.next();
        query.prepare("{call getFavDirector(?)}");
        query.bindValue(0, myAc.id);
        query.exec();
        query.next();
        ui->lSetFavDirector->setText(query.value(0).toString());
    }
    else
    {
        QList<QGroupBox*> boxList = ui->tabWidget->widget(index)->findChildren<QGroupBox*>();
        for(int i = 0; i < boxList.size(); i++)
            boxList.value(i)->close();
        if(index == 1)
        {
            QSqlQuery query;
            query.prepare("{call getMovie}");
            query.exec();
            int iter = 1;
            while (query.next())
            {
                QGroupBox *box = new QGroupBox(ui->tabWidget->widget(1));
                QVBoxLayout *panelLayout = new QVBoxLayout(box);
                QHBoxLayout *buttonLayout = new QHBoxLayout();
                boxLayout->addWidget(box);
                box->setTitle(QString::number(iter++) + " " + query.value(0).toString());
                QLabel *lDirector = new QLabel(box);
                panelLayout->addWidget(lDirector);
                lDirector->setText("Режисер: " + query.value(1).toString());
                QLabel *lActors = new QLabel(box);
                panelLayout->addWidget(lActors);
                lActors->setText("Актеры: " + query.value(2).toString());
                QPushButton *btFavM = new QPushButton(box);
                QPushButton *btRating = new QPushButton(box);
                btFavM->setText("Сделать любимым фильмом " + query.value(0).toString());
                btRating->setText("Поставить оценку " + query.value(0).toString());
                connect(btFavM, SIGNAL(released()), this, SLOT(on_btFav_clicked()));
                connect(btRating, SIGNAL(clicked()), this, SLOT(on_btRating_clicked()));
                btFavM->setObjectName("M:" + query.value(0).toString());
                btRating->setObjectName(query.value(0).toString());
                buttonLayout->addWidget(btFavM);
                buttonLayout->addWidget(btRating);
                panelLayout->addLayout(buttonLayout);
                box->show();
            }
        }
        else if(index == 2)
        {
            QSqlQuery query;
            query.prepare("{call getActors}");
            query.exec();
            int iter = 1;
            while (query.next())
            {
                QGroupBox *box = new QGroupBox(ui->tabWidget->widget(2));
                QVBoxLayout *panelLayout = new QVBoxLayout(box);
                boxLayoutA->addWidget(box);
                box->setTitle(QString::number(iter++) + " " + query.value(0).toString());
                QLabel *lMovies = new QLabel(box);
                panelLayout->addWidget(lMovies);
                lMovies->setText("Фильмы: " + query.value(1).toString());
                QPushButton *btFavA = new QPushButton(box);
                btFavA->setText("Сделать любимым актером " + query.value(0).toString());
                btFavA->setObjectName("A:" + query.value(0).toString());
                connect(btFavA, SIGNAL(released()), this, SLOT(on_btFav_clicked()));
                panelLayout->addWidget(btFavA);
                box->show();
            }
        }
        else if(index == 3)
        {
            QSqlQuery query;
            query.prepare("{call getDirectors}");
            query.exec();
            int iter = 1;
            while (query.next())
            {
                QGroupBox *box = new QGroupBox(ui->tabWidget->widget(3));
                QVBoxLayout *panelLayout = new QVBoxLayout(box);
                boxLayoutD->addWidget(box);
                box->setTitle(QString::number(iter++) + " " + query.value(0).toString());
                QLabel *lMovies = new QLabel(box);
                panelLayout->addWidget(lMovies);
                lMovies->setText("Фильмы: " + query.value(1).toString());
                QPushButton *btFavD = new QPushButton(box);
                btFavD->setText("Сделать любимым режиссером " + query.value(0).toString());
                btFavD->setObjectName("D:" + query.value(0).toString());
                connect(btFavD, SIGNAL(released()), this, SLOT(on_btFav_clicked()));
                panelLayout->addWidget(btFavD);
                box->show();
            }
        }
        else if(index == 4)
        {
            QSqlQuery query;
            query.prepare("{call getRating(?)}");
            query.bindValue(0, myAc.id);
            query.exec();
            int iter = 1;
            while (query.next())
            {
                QGroupBox *box = new QGroupBox(ui->tabWidget->widget(4));
                QVBoxLayout *panelLayout = new QVBoxLayout(box);
                boxLayoutR->addWidget(box);
                box->setTitle(QString::number(iter++) + " " + query.value(0).toString());
                QLabel *lMyRat = new QLabel(box);
                panelLayout->addWidget(lMyRat);
                lMyRat->setText("Ваша оценка: " + query.value(1).toString());
                QLabel *lAvRat = new QLabel(box);
                panelLayout->addWidget(lAvRat);
                lAvRat->setText("Средняя оценка: " + query.value(2).toString());
                box->show();
            }
        }
    }

}

void MainWindow::on_btFav_clicked()
{
    QList<QString> favList = this->sender()->objectName().split(":");
    if(favList[0] == "M")
    {
        ui->lSetFavMovie->setText(favList[1]);
        QSqlQuery query;
        query.prepare("{call setFavMovie(?, ?)}");
        query.bindValue(0, favList[1]);
        query.bindValue(1, myAc.id);
        query.exec();
        query.next();
    }
    else if(favList[0] == "A")
    {
        ui->lSetFavActor->setText(favList[1]);
        QSqlQuery query;
        query.prepare("{call setFavActor(?, ?)}");
        query.bindValue(0, favList[1]);
        query.bindValue(1, myAc.id);
        query.exec();
        query.next();
    }
    else if(favList[0] == "D")
    {
        ui->lSetFavDirector->setText(favList[1]);
        QSqlQuery query;
        query.prepare("{call setFavDirector(?, ?)}");
        query.bindValue(0, favList[1]);
        query.bindValue(1, myAc.id);
        query.exec();
        query.next();
    }
}

void MainWindow::on_btRating_clicked()
{
    bool bOk;
    int rating = QInputDialog::getInt(0,
                                         "Оценка фильма",
                                         "Выбирите значение от 0 до 10",
                                         0,
                                         0,
                                         10,
                                         1,
                                      &bOk
                                        );
    if(!bOk)
        return;
    QSqlQuery query;
    query.prepare("{call setRating(?, ?, ?)}");
    query.bindValue(0, this->sender()->objectName());
    query.bindValue(1, myAc.id);
    query.bindValue(2, rating);
    query.exec();
    query.next();
}


void MainWindow::on_btSearch_clicked()
{
    QSqlQuery query;
    query.prepare("{call findMovie(?)}");
    query.bindValue(0, ui->leSearch->text());
    query.exec();
    query.next();
    if(!query.value(0).isNull())
    {
        ui->lMyMovie->setText(query.value(0).toString());
        ui->lFindDirector->setText(query.value(1).toString());
        ui->lFindActors->setText(query.value(2).toString());
        ui->lFindRating->setText(query.value(3).toString());
        ui->btFavMovie->setObjectName("M:" + query.value(0).toString());
        ui->btSetRating->setObjectName(query.value(0).toString());
    }
    else
        ui->lMyMovie->setText("Такого фильма нет");
}
