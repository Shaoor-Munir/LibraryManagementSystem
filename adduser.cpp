#include "adduser.h"
#include "ui_adduser.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"clerk.h"
#include"QMessageBox"
#include"mainwindow.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
     LMS_S *obj = new LMS_S();
     User * u = obj->return_logged_user();

     if(u->return_type() == "clerk")
     {
         ui->in_type->clear();

         ui->in_type->insertItem(0, "Student");
     }

}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_buttonBox_accepted()
{

    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    string selection = ui->in_type->currentText().toStdString();

    QString name = ui->in_name->text();
    QString uname = ui->in_uname->text();
    QString pass = ui->in_pass->text();
    QString address = ui->in_adress->text();
    QString phone = ui->in_phone->text();
    QString type = ui->in_type->currentText();

   if(type == "Admin")
   {
       type = "admin";
   }
   else if(type == "Clerk")
   {
       type = "clerk";
   }
   else
   {
       type = "student";
   }

    QSqlQuery query;
    query.prepare("execute add_user @input_name = ?,@input_uname = ?,@input_password = ?,@output_id  = ? output,@phone = ?,@input_address = ?,@type = ?");

    query.bindValue(0, name);

    query.bindValue(1, uname);

    query.bindValue(2, pass);

    query.bindValue(3, 0, QSql::Out);

    query.bindValue(4, phone);

    query.bindValue(5, address);

    query.bindValue(6, type);

    query.exec();

    int id = query.boundValue(3).toInt();


    cout<<id<<endl;


    QMessageBox message;

    if(id == -1)
    {

        message.setText("Cannot add user, Username may already exist in database.");
    }
    else
    {
        User * u;
        if(type == "admin")
        {
            u =  new Admin(id, name.toStdString(),uname.toStdString(), phone.toStdString(), address.toStdString(), pass.toStdString());
        }
        else if(type =="clerk")
        {
            u = new Clerk(id, name.toStdString(), uname.toStdString(), phone.toStdString(), address.toStdString(), pass.toStdString());
        }
        else
        {
            u = new Student(id, name.toStdString(), uname.toStdString(), phone.toStdString(), address.toStdString(), pass.toStdString());
        }

        library->add_User(u);

        message.setText("User has been created successfully.");
    }

    message.exec();
}
