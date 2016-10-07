#include "login.h"
#include "ui_login.h"
#include"QString"
#include"qsqlquery.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"loginerror.h"
#include"QMessageBox"
#include"adminmainwindow.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttons_accepted()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
/*
    QSqlQuery query;

    query.prepare("declare @output_authkey varchar(50), @output_userName varchar(50,@output_type varchar(50),@output_name varchar(100);"
                  "exec login @input_uname = ?, @input_pass = ?,"
                  "@output_authkey varchar(50), @output_userName varchar(50,@output_type varchar(50),@output_name varchar(100)");

                  */
    LMS_S *obj = new LMS_S();

    LMS * library = obj->return_library();

    User * curr_user = library->login_user(username.toStdString(), password.toStdString());

    if(curr_user != nullptr)
    {
        obj->add_logged_user(curr_user);

        if(curr_user->return_type()=="admin")
        {
            AdminMainWindow * adminwindow = new AdminMainWindow();
            adminwindow->show();
        }


    }

    else
    {
        QMessageBox box;
        box.setText("Username or password is incorrect. Please check again.");
        box.exec();
        ui->setupUi(this);
    }

}
