#include "onholdstate.h"
#include"loanitem.h"
#include"lms_s.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

onHoldState::onHoldState()
{

}

void onHoldState::issueBook(LibItem * item, User * user)
{
    bool issueItem = false;
    QSqlQuery query;
    query.prepare("select top1 userID from onHoldItems where itemID=?");
    query.bindValue(0, item->get_id());
    query.exec();

    if(query.next())
    {
        int uID = query.value(0).toInt();

        if(uID == user->get_id())
        {
            QMessageBox *box =  new QMessageBox();
            box->setText("Item was on hold by the same user. The book can be issued safely.");
            box->show();
            issueItem = true;

        }
        else
        {
            issueItem = false;
        }
    }

    if(!issueItem)
    {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(NULL, "Item on Hold", "This item is on hold by another user. Do you still want to issue this item?", QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {

            issueItem = true;
        }
        else
        {
            qDebug() << "Yes was *not* clicked";
        }
    }
    if(issueItem)
    {
        query.prepare("insert into LoanItems(userID, itemID, iDate) values (?, ?, GETDATE())");
        query.bindValue(0, user->get_id());
        query.bindValue(1, item->get_id());
        query.exec();

        query.prepare("select top 1 loanID, iDate from LoanItems where userID=? and itemID=? order by loanID desc");
        query.bindValue(0, user->get_id());
        query.bindValue(1, item->get_id());
        query.exec();

        if(query.next())
        {

            int id = query.value(0).toInt();
            string iDate = query.value(1).toString().toStdString();

            cout<<id<<"  "<<iDate<<endl;
            LoanItem * l = new LoanItem(user, item, id, iDate);
            QMessageBox *box =  new QMessageBox();
            box->setText("Item has been successfully loaned out");
            box->show();

            LMS_S * obj = new LMS_S();
            item->set_state(obj->return_unavailable());


            query.prepare("update LibItems set itemState = 'unavailable' where itemID=?");
            query.bindValue(0, item->get_id());
            query.exec();

            query.prepare("delete from onHoldItems where itemID=? and userID=?");
            query.bindValue(0, item->get_id());
            query.bindValue(1, user->get_id());
            query.exec();

            cout<<"Hold has been removed."<<endl;

        }

    }
}

string onHoldState::return_state()
{
    return "onHold";
}
