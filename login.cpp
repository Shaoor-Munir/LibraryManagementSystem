#include "login.h"
#include"mainwindow.h"
#include "ui_login.h"
#include"QString"
#include"myDAL.h"
#include"qsqlquery.h"

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

    QSqlQuery query;

    query.prepare("declare @output_authkey varchar(50), @output_userName varchar(50,@output_type varchar(50),@output_name varchar(100);"
                  "exec login @input_uname = ?, @input_pass = ?,"
                  "@output_authkey varchar(50), @output_userName varchar(50,@output_type varchar(50),@output_name varchar(100)
}
