#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login LoginWin;
    LoginWin.show();
    return a.exec();
}
