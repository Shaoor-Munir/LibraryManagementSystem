#include "loginwindow.h"
#include "ui_loginwindow.h"
#include"QString"
#include"qsqlquery.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"QMessageBox"
#include"mainwindow.h"
loginMainWIndow::loginMainWIndow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginMainWIndow)
{
    ui->setupUi(this);
}

loginMainWIndow::~loginMainWIndow()
{
    delete ui;
}

void loginMainWIndow::on_buttonBox_accepted()
{
    QString username = ui->username->text();
    QString password = ui->password->text();



    LMS_S *obj = new LMS_S();

    LMS * library = obj->return_library();

    User * curr_user = library->login_user(username.toStdString(), password.toStdString());

    if(curr_user != nullptr)
    {
        obj->add_logged_user(curr_user);

        MainWindow * adminwindow = new MainWindow();
        adminwindow->show();
        this->deleteLater();

    }

    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Error", "Username or password is incorrect, try again.");
        //box.setText("Username or password is incorrect. Please check again.");
        box->setFixedSize(500, 200);

    }

}

void loginMainWIndow::on_buttonBox_rejected()
{
    this->close();
}
