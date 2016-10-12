#include "removeloan.h"
#include "ui_removeloan.h"
#include"lms.h"
#include"lms_s.h"
#include"user.h"
#include"libitem.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

RemoveLoan::RemoveLoan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RemoveLoan)
{
    ui->setupUi(this);
    ui->LoanDetails->hide();
}

RemoveLoan::~RemoveLoan()
{
    delete ui;
}

void RemoveLoan::on_search_button_clicked()
{
    ui->LoanDetails->hide();
    int userID = ui->in_userID->text().toInt();
    int itemID = ui->in_itemID->text().toInt();

    LMS_S obj;

    LMS *library = obj.return_library();

    User * u = library->search_User(userID);

    vector<LoanItem *> pending_loans = u->return_pending_loans();

    bool LoanFound = false;
    for(int i=0;i<pending_loans.size() && !LoanFound;i++)
    {
        if((pending_loans[i]->get_item())->get_id() == itemID)
        {
            loan = pending_loans[i];
            LoanFound = true;
        }
    }

    if(LoanFound)
    {
        ui->LoanDetails->show();
        ui->out_loanID->setText(QString::number(loan->get_id()));
        ui->iDate->setText(QString::fromStdString(loan->return_iDate()));
    }
    else
    {
        QMessageBox *box =  new QMessageBox(this);
        box->critical(0, "Search Error", "No pending loan with this userID and itemID was found, try again.");
        box->setFixedSize(500, 200);
    }


}

void RemoveLoan::on_check_in_button_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Check in Item", "Are you sure you want to check in this item?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          QSqlQuery query;

          query.prepare("update LoanItems set rDate = GETDATE() where loanID=?");
          query.bindValue(0, loan->get_id());
          query.exec();

          query.prepare("select rDate from LoanItems where loanID = ?");
          query.bindValue(0, loan->get_id());
          query.exec();


          if(query.next())
          {

            string rDate = query.value(0).toString().toStdString();

            cout<<rDate<<endl;
            loan->returnItem(rDate);


            QMessageBox message;
             message.setText("Item has successfuly been checked in.");
            message.exec();
          }
          else
              cout<<"Error"<<endl;
      }
      else
      {
        qDebug() << "Yes was *not* clicked";
      }
}

void RemoveLoan::on_renew_button_clicked()
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Renew Item", "Are you sure you want to renew this item?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          QSqlQuery query;
          query.prepare("update LoanItems set iDate = GETDATE() where loanID =? ");
          query.bindValue(0, loan->get_id());
          query.exec();

          query.prepare("select iDate from LoanItems where loanID = ?");
          query.bindValue(0, loan->get_id());
          query.exec();

          if(query.next())
          {
            string iDate = query.value(0).toString().toStdString();
            cout<<iDate<<endl;
            loan->renew_loan(iDate);

            QMessageBox message;
            message.setText("Loan has successfully been renewed.");
            message.exec();
          }
          else
              cout<<"Error"<<endl;

      }
      else
      {
        qDebug() << "Yes was *not* clicked";
      }
}
