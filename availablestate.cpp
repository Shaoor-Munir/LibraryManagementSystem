#include "availablestate.h"
#include"lms_s.h"
#include"loanitem.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>


availableState::availableState()
{

}
void availableState::issueBook(LibItem *item, User *user)
{
    QSqlQuery query;
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

        cout << id <<"  " << iDate << endl;
        LoanItem * l = new LoanItem(user, item, id, iDate);

        query.prepare("update LibItems set itemState = 'unavailable' where itemID=?");
        query.bindValue(0, item->get_id());
        query.exec();

        QMessageBox *box =  new QMessageBox();
        box->setText("Item has been successfully loaned out");
        box->show();

        LMS_S * obj =  new LMS_S();
        item->set_state(obj->return_unavailable());


        query.prepare("delete from onHoldItems where itemID=? and userID=?");
        query.bindValue(0, item->get_id());
        query.bindValue(1, user->get_id());
        query.exec();

        cout<<"Hold has been removed."<<endl;
    }
}

string availableState::return_state()
{
    return "available";
}
