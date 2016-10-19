#include "referencestate.h"
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>

referenceState::referenceState()
{

}
void referenceState::issueBook(LibItem * item, User * user)
{
    QMessageBox *box =  new QMessageBox();
    box->critical(0, "Error", "This book is for reference only, you cannot issue it.");
    box->setFixedSize(500, 200);

}

string referenceState::return_state()
{
    return "reference";
}
