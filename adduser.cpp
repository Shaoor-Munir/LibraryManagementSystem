#include "adduser.h"
#include "ui_adduser.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"clerk.h"
#include"loginerror.h"
#include"QMessageBox"
#include"adminmainwindow.h"


AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_buttonBox_accepted()
{

    LMS_S *obj = new LMS_S();
    bool check = false;
    LMS * library = obj->return_library();

    string selection = ui->in_type->currentText().toStdString();

    string name = ui->in_name->text().toStdString();
    string uname = ui->in_uname->text().toStdString();
    string pass = ui->in_pass->text().toStdString();

    if(selection == "Admin")
    {
        Admin * a = new Admin(name, uname, pass);
        check  = library->add_User(a);
    }
    else if(selection == "Clerk")
    {
        Clerk * c = new Clerk(name, uname, pass);
        check  = library->add_User(c);

    }
    else if(selection == "Student")
    {
        Student * s = new Student(name, uname, pass);
        check  = library->add_User(s);
    }

    QMessageBox message;

    if(check == false)
    {

        message.setText("Cannot add user, Username may already exist in database.");
    }
    else
    {
        message.setText("User has been created successfully.");
    }

    message.exec();
}
