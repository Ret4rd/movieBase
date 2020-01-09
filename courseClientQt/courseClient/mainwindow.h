#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql/QSqlDatabase"
#include "account.h"
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSqlDatabase db;
    Account myAc;
    void setDb(QSqlDatabase db);
    void setMaxAccount(QString id, QString firstName, QString secondName, QString loginClient, QString passwordClient,
                    QString favMovie, QString favDirector, QString favActor);
    void setMinAccount(QString id, QString firstName, QString loginClient, QString passwordClient, QSqlQuery query);
    QVBoxLayout *boxLayout;
    QVBoxLayout *boxLayoutA;
    QVBoxLayout *boxLayoutD;
    QVBoxLayout *boxLayoutR;

private slots:
    void on_btChange_clicked();
    void on_btOk_clicked();
    void on_btFav_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_btRating_clicked();

    void on_btSearch_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
