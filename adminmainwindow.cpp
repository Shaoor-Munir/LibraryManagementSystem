#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"QMessageBox"
#include"adduser.h"
#include"additem.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);

    LMS_S *obj = new LMS_S();

    LMS * library = obj->return_library();

    User * curr_user = obj->return_logged_user();

    ui->NDisplay->setText(QString::fromStdString(curr_user->get_name()));

    ui->UDisplay->setText(QString::fromStdString(curr_user->get_username()));
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::on_add_user_button_clicked()
{
    AddUser * add = new AddUser();
    add->show();
}

void AdminMainWindow::on_add_item_button_clicked()
{
    AddItem * add = new AddItem();
    add->show();
}
