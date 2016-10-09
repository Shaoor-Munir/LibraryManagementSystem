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
    }
    else
    {
        ui->extraDetail->setText("Category");
    }
}

void AddItem::on_buttonBox_accepted()
{
    LMS_S *obj = new LMS_S();
    LMS * library = obj->return_library();

    QString type = ui->in_type->currentText();
    QString name = ui->in_name->text();
    QString category = "";
    QString author ="";

    if(type == "Book")
    {
        type = "book";
        author = ui->in_extra->text();
    }
    else
    {
        type = "dvd";
        category = ui->in_extra->text();
    }

    QSqlQuery query;
    query.prepare("execute add_item @input_name=?, @input_author=?, @input_category=?, @input_type=?, @output_id=? output");

    query.bindValue(0, name);

    if(type == "book")
        query.bindValue(1, author);
    else
        query.bindValue(2, category);

    query.bindValue(3, type);
    query.bindValue(4, 0, QSql::Out);

    query.exec();



    int id = query.boundValue(4).toInt();

     cout<<id<<endl;

    if(type == "Book")
    {
        Book * b = new Book(id, name.toStdString(), author.toStdString());
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
