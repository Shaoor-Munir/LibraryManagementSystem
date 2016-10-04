#include "mainwindow.h"
#include"login.h"
#include <QApplication>
#include"myDAL.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    myDAL database;

    Login * w  =  new Login();
    w->show();

    return a.exec();
}
