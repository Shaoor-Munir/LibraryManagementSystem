#include "login.h"
#include "ui_login.h"
#include"QString"
#include"myDAL.h"
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

    Admin * a = new Admin("Shaoor Munir", "shaoor", "apple123");
    Student *s = new Student ("Haseeb Ahmed", "haseeb", "fogger345");

    library->add_User(a);
    library->add_User(s);

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
    }

}
