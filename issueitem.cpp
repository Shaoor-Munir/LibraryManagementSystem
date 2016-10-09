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

        itemAavailable = current_item->check_availability();

        if(itemAavailable)
        {
            bool onHold = false;
            QSqlQuery query;
            query.prepare("select * from onHoldItems where itemID = ?");
            query.bindValue(0, current_item->get_id());

            query.exec();
            if(query.next())
            {
                cout<<"Checking if current user is holding the book."<<endl;
                if(current_user != nullptr)
                {
                    query.prepare("select top 1 holdID from onHoldItems where userID = ? and itemID = ?");
                    query.bindValue(0, current_user->get_id());
                    query.bindValue(1, current_item->get_id());
                    query.exec();

                    if(query.next())
                    {
                        onHold = false;
                    }
                }
                else
                    onHold = true;
            }

            if(onHold)
            {
                itemAavailable = false;

                ui->IAvailabilityLabel->setText("Item is put on hold for another user");
                ui->issue_button->setText("Put on Hold");
            }
            else
            {

                ui->IAvailabilityLabel->setText("Item is available for loan");
                ui->issue_button->setText("Issue Item");
            }
        }
        else
        {
            ui->IAvailabilityLabel->setText("Item is currently loaned out. You can put it on hold");
            ui->issue_button->setText("Put on Hold");
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
        if(itemAavailable)
        {

            QSqlQuery query;
            query.prepare("insert into LoanItems(userID, itemID, iDate) values (?, ?, GETDATE())");
            query.bindValue(0, current_user->get_id());
            query.bindValue(1, current_item->get_id());

            query.exec();

            query.prepare("select top 1 loanID, iDate from LoanItems where userID=? and itemID=? order by loanID desc");
            query.bindValue(0, current_user->get_id());
            query.bindValue(1, current_item->get_id());
            query.exec();
            query.first();
            int id = query.value(0).toInt();
            string iDate = query.value(1).toString().toStdString();

            cout<<id<<"  "<<iDate<<endl;
            LoanItem * l = new LoanItem(current_user, current_item, id, iDate);
            QMessageBox *box =  new QMessageBox(this);
            box->setText("Item has been successfully loaned out");
            box->show();
        }
        else
        {
            QSqlQuery query;
            query.prepare("execute hold_item @input_userID=?, @input_itemId=?, @output_holdID=? output");
            query.bindValue(0, current_user->get_id());
            query.bindValue(1, current_item->get_id());
            query.bindValue(2, 0, QSql::Out);

            query.exec();

            int holdID = query.boundValue(2).toInt();

            if(holdID >= 0)
            {
                QMessageBox *box =  new QMessageBox(this);
                box->setText("Item has been successfully put on hold.");
                box->show();
            }
        }
    }
}
