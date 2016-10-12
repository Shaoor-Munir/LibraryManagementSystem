#include "edititem.h"
#include "ui_edititem.h"
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

EditItem::EditItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditItem)
{
    ui->setupUi(this);
    ui->ItemDetails->hide();
}

EditItem::~EditItem()
{
    delete ui;
}

void EditItem::on_search_button_clicked()
{
    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    this->item = library->search_LibItem(ui->in_itemID->text().toInt());

    if(item!=nullptr)
    {
        ui->ItemDetails->show();

        if(item->return_type() == "book")
        {
            ui->Extra_Label->setText("Author");
            ui->in_subject->show();
            ui->Subject_label->show();
            ui->Extra_Label->show();

            ui->in_extra->setText(QString::fromStdString(((Book*)item)->get_author()));
            ui->in_subject->setText(QString::fromStdString(((Book*)item)->get_subject()));
        }
        else
        {
            ui->Extra_Label->setText("Category");
            ui->in_subject->clear();
            ui->in_subject->hide();
            ui->Subject_label->hide();


            ui->in_extra->setText(QString::fromStdString(((DVD*)item)->get_category()));
        }

        ui->in_title->setText(QString::fromStdString(item->get_name()));
        ui->in_type_2->setText(QString::fromStdString(item->return_type()));
    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Search Error", "No item with this ID was found, try again.");
        box->setFixedSize(500, 200);
    }
}

void EditItem::on_delete_button_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Delete User", "Are you sure you want to delete this Item?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          LMS_S *obj = new LMS_S();
          LMS * library = obj->return_library();

          library->remove_LibItem(item->get_id());

          QSqlQuery query;
          query.prepare("delete from LibItems where itemID=?");
          query.bindValue(0, item->get_id());
          query.exec();

          qDebug() << "Yes was clicked";
          QMessageBox *box =  new QMessageBox(this);
          box->setText("Item has been successfuly deleted from database.");
          ui->in_itemID->clear();
          ui->ItemDetails->hide();
          box->show();
      }
      else
      {
        qDebug() << "Yes was *not* clicked";
      }

}

void EditItem::on_update_button_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Delete User", "Are you sure you want to update information for this Item?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          LMS_S *obj = new LMS_S();
          LMS * library = obj->return_library();
          QString title = ui->in_title->text();
          QString author = "";
          QString category = "";
          QString subject = ui->in_subject->text();

          if(item->return_type() == "book")
          {
              author = ui->in_extra->text();
              ((Book * ) item)->update_info(title.toStdString(), author.toStdString(), subject.toStdString());

              QSqlQuery query;
              query.prepare("Update LibItems set iName=?, author=?,bSubject=? where itemID = ?");
              query.bindValue(0, title);
              query.bindValue(1, author);
              query.bindValue(2, subject);
              query.bindValue(3, item->get_id());
              query.exec();

          }
          else
          {
              category = ui->in_extra->text();
              ((DVD *)item)->update_info(title.toStdString(),category.toStdString());

              QSqlQuery query;
              query.prepare("Update LibItems set iName=?, category=? where itemID = ?");
              query.bindValue(0, title);
              query.bindValue(1, category);
              query.bindValue(2, item->get_id());
              query.exec();

          }

          qDebug() << "Yes was clicked";
          QMessageBox *box =  new QMessageBox(this);
          box->setText("Item information has been successfuly updated.");
          box->show();
      }
      else
      {
        qDebug() << "Yes was *not* clicked";
      }
}
