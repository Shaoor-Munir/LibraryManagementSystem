#include "additem.h"
#include "ui_additem.h"
#include "lms_s.h"
#include"book.h"
#include"dvd.h"
#include"QMessageBox"
#include"mainwindow.h"
#include"QMessageBox"
#include"mainwindow.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::on_in_type_currentIndexChanged()
{
    string type = ui->in_type->currentText().toStdString();

    if(type == "Book")
    {
        ui->extraDetail->setText("Author");
        ui->SubjectLabel->show();
        ui->in_subject->show();
    }
    else
    {
        ui->extraDetail->setText("Category");
        ui->SubjectLabel->hide();
        ui->in_subject->hide();
    }
}

void AddItem::on_buttonBox_accepted()
{
    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    QString type = ui->in_type->currentText();
    QString name = ui->in_name->text();
    QString subject = "";
    QString category = "";
    QString author ="";

    if(type == "Book")
    {
        type = "book";
        author = ui->in_extra->text();
        subject = ui->in_subject->text();
    }
    else
    {
        type = "dvd";
        category = ui->in_extra->text();
    }

    QSqlQuery query;
    query.prepare("execute add_item @input_name=?, @input_author=?, @input_subject=?, @input_category=?, @input_type=?, @output_id=? output");

    query.bindValue(0, name);

    if(type == "book")
    {
        query.bindValue(1, author);
        query.bindValue(2, subject);
    }
    else
        query.bindValue(3, category);

    query.bindValue(4, type);
    query.bindValue(5, 0, QSql::Out);

    query.exec();



    int id = query.boundValue(5).toInt();

     cout<<id<<endl;

    if(type == "Book")
    {
        Book * b = new Book(id, name.toStdString(), author.toStdString(), subject.toStdString());
        library->add_LibItem(b);
    }
    else
    {
        DVD * dvd =  new DVD(id, name.toStdString(), category.toStdString());
        library->add_LibItem(dvd);
    }

    QMessageBox message;

    message.setText("LibItem has been successfully added.");
    message.exec();
    this->close();
}
