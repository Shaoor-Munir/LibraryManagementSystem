#include "issueitem.h"
#include "ui_issueitem.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

IssueItem::IssueItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IssueItem)
{
    ui->setupUi(this);
    LMS_S * obj =  new LMS_S();
    current_item = nullptr;
    current_user = nullptr;
    library = obj->return_library();
}

IssueItem::~IssueItem()
{
    delete ui;
}

void IssueItem::on_userID_search_button_clicked()
{
    current_user = library->search_User(ui->userID->text().toInt());

    if(current_user != nullptr)
    {
        ui->UNameLabel->setText(QString::fromStdString(current_user->get_name()));
        ui->UUNameLabel->setText(QString::fromStdString(current_user->get_username()));
    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Search Error", "No user with this ID was found, try again.");
        box->setFixedSize(500, 200);

        ui->UNameLabel->setText("Not Available");
        ui->UUNameLabel->setText("Not Available");
    }

}

void IssueItem::on_itemID_search_button_clicked()
{
    current_item = library->search_LibItem(ui->itemID->text().toInt());


    if(current_item!=nullptr)
    {

        if(current_item->check_availability() == "available")
        {
            ui->IAvailabilityLabel->setText("Item is available for user to issue.");
            ui->issue_button->setText("Issue Item");
            ui->issue_button->show();
        }
        else if( current_item->check_availability()=="unavailable")
        {
            ui->IAvailabilityLabel->setText("Item is not available and can be put on hold");
            ui->issue_button->setText("Put on Hold");
            ui->issue_button->show();
        }
        else if(current_item->check_availability()=="reference")
        {
            ui->IAvailabilityLabel->setText("Item is for referenc only and cannot be issued to any user");
            ui->issue_button->hide();
        }
        else
        {
            ui->IAvailabilityLabel->setText("Item is on hold by another user. You can override it and issue it to the user");
            ui->issue_button->setText("Issue item");
            ui->issue_button->show();
        }

        ui->INameLabel->setText(QString::fromStdString(current_item->get_name()));

        if(current_item->return_type() == "book")
        {
            ui->ExtraLabel->setText("Author");

            ui->IExtraLabel->setText(QString::fromStdString(((Book*)current_item)->get_author()));

        }
        else
        {
            ui->ExtraLabel->setText("Category");
            ui->IExtraLabel->setText(QString::fromStdString(((DVD*)current_item)->get_category()));
        }

    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Search Error", "No item with this ID was found, try again.");
        box->setFixedSize(500, 200);
        ui->INameLabel->setText("Not Available");
        ui->IExtraLabel->setText("Not Available");
        ui->IAvailabilityLabel->setText("Not Available");
    }

}

void IssueItem::on_issue_button_clicked()
{
    if(current_user == nullptr)
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Error", "Please enter User details to complete checkout");
        box->setFixedSize(500, 200);
    }
    else if(current_item == nullptr)
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Error", "Please enter Item details to complete checkout");
        box->setFixedSize(500, 200);
    }
    else
    {
        current_item->issueBook(current_user);
    }
}
