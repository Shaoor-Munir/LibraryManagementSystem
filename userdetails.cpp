#include "userdetails.h"
#include "ui_userdetails.h"
#include"lms.h"
#include"user.h"
#include"lms_s.h"

UserDetails::UserDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserDetails)
{
    ui->setupUi(this);

    LMS_S * obj = new LMS_S();

    User * temp = obj->return_logged_user();

    ui->UName->setText(QString::fromStdString(temp->get_name()));
    ui->UUName->setText(QString::fromStdString(temp->get_username()));
    ui->uNumber->setText(QString::fromStdString(temp->get_number()));
    ui->UAdress->setText(QString::fromStdString(temp->get_address()));

}

UserDetails::~UserDetails()
{
    delete ui;
}
