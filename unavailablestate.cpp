#include "unavailablestate.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>
#include"lms_s.h"

unavailableState::unavailableState()
{

}
void unavailableState::issueBook(LibItem *item, User *user)
{

    QMessageBox::StandardButton reply;
          reply = QMessageBox::question(NULL, "Unavailable Item", "This book is currently on loan. Do you want to put it on hold for the current user?", QMessageBox::Yes|QMessageBox::No);

          if (reply == QMessageBox::Yes)
          {
              QSqlQuery query;
              query.prepare("execute hold_item @input_userID=?, @input_itemId=?, @output_holdID=? output");
              query.bindValue(0, user->get_id());
              query.bindValue(1, item->get_id());
              query.bindValue(2, 0, QSql::Out);
              query.exec();

              int holdID = query.boundValue(2).toInt();

              if(holdID > 0)
              {

                  query.prepare("update LibItems set itemState = 'onHold' where itemID=?");
                  query.bindValue(0, item->get_id());
                  query.exec();

                  QMessageBox *box =  new QMessageBox();
                  box->setText("Item has been successfully put on hold.");
                  box->show();
              }
          }
          else
          {
            qDebug() << "Yes was *not* clicked";
          }

}

string unavailableState::return_state()
{
    return "unavailable";
}
