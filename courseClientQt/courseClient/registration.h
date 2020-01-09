#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include "login.h"
#include "mainwindow.h"

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

private slots:
    void on_btReg_clicked();

private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
