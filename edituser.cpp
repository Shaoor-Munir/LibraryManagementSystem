#include "edituser.h"
#include "ui_edituser.h"
#include"lms_s.h"
#include"lms.h"
#include"QMessageBox"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

EditUser::EditUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditUser)
{
    ui->setupUi(this);
    ui->UserDetails->hide();
}

EditUser::~EditUser()
{
    delete ui;
}

void EditUser::on_search_button_clicked()
{
    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    this->u = library->search_User(ui->in_userID->text().toInt());

    if(u!=nullptr)
    {
        ui->UserDetails->show();
        ui->in_name->setText(QString::fromStdString(u->get_name()));
        ui->in_uname->setText(QString::fromStdString(u->get_username()));
        ui->in_address->setText(QString::fromStdString(u->get_address()));
        ui->in_phone->setText(QString::fromStdString(u->get_number()));
        ui->in_pass->setText(QString::fromStdString(u->get_password()));
        ui->in_type->setText(QString::fromStdString(u->return_type()));
    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Search Error", "No user with this ID was found, try again.");
        box->setFixedSize(500, 200);
    }
}

void EditUser::on_delete_button_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Delete User", "Are you sure you want to delete this user?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          LMS_S *obj = new LMS_S();
          LMS * library = obj->return_library();

          library->remove_user(u->get_id());

          QSqlQuery query;
          query.prepare("delete from Users where userID=?");
          query.bindValue(0, u->get_id());
          query.exec();

          qDebug() << "Yes was clicked";
          QMessageBox *box =  new QMessageBox(this);
          box->setText("User has been successfuly deleted from database.");
          ui->in_userID->clear();
          ui->UserDetails->hide();
          box->show();
      }
      else
      {
        qDebug() << "Yes was *not* clicked";
      }

}

void EditUser::on_update_button_clicked()
{
    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    if(library->check_username(ui->in_uname->text().toStdString(), u))
    {
        u->update_info(ui->in_name->text().toStdString(),ui->in_uname->text().toStdString(), ui->in_address->text().toStdString(), ui->in_phone->text().toStdString(), ui->in_pass->text().toStdString());

        QSqlQuery query;
        query.prepare("update Users set aName =?, uName=?, uPassword=?, phoneNumber=?, uAddress=? where userID =?");

        query.bindValue(0, ui->in_name->text());
        query.bindValue(1, ui->in_uname->text());
        query.bindValue(2, ui->in_pass->text());
        query.bindValue(3, ui->in_phone->text());
        query.bindValue(4, ui->in_address->text());
        query.bindValue(5, ui->in_userID->text().toInt());

        query.exec();

        QMessageBox *box =  new QMessageBox(this);
        box->setText("User data has been successfuly updated.");
        box->show();
        on_search_button_clicked();

    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Username Error", "There is already a user with this username. Try again.");
        box->setFixedSize(500, 200);
    }
}
