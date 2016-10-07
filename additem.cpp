#include "additem.h"
#include "ui_additem.h"
#include "lms_s.h"
#include"book.h"
#include"dvd.h"
#include"loginerror.h"
#include"QMessageBox"
#include"adminmainwindow.h"
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

void AddItem::on_in_type_currentIndexChanged(const QString &arg1)
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

    string type = ui->in_type->currentText().toStdString();
    string name = ui->in_name->text().toStdString();
    string extra = ui->in_extra->text().toStdString();

    /*
    if(type == "Book")
    {
        Book * b = new Book(name, extra);
        library->add_LibItem(b);
    }
    else
    {
        DVD * dvd =  new DVD(name, extra);
        library->add_LibItem(dvd);
    }
    */
    QMessageBox message;

    message.setText("LibItem has been successfully added.");
    message.exec();
}
