#include"loginwindow.h"
#include"lms_s.h"
#include"user.h"
#include"state.h"
#include"admin.h"
#include"clerk.h"
#include"student.h"
#include"libitem.h"
#include"loanitem.h"
#include"dvd.h"
#include"book.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>
#include<iostream>

#include <QApplication>


void load_data()
{
    LMS_S *obj = new LMS_S();

    LMS * library = obj->return_library();

    QSqlQuery query;

    query.prepare("Select * from Users");
    query.exec();

    while(query.next())
    {
        cout<<"Loading users"<<endl;
        int id = query.value(0).toInt();
        string name = query.value(1).toString().toStdString();
        string uname = query.value(2).toString().toStdString();
        string password = query.value(3).toString().toStdString();
        string phone_number = query.value(4).toString().toStdString();
        string address = query.value(5).toString().toStdString();
        string type = query.value(6).toString().toStdString();

        cout <<" "<<name<<" "<<uname<<" "<<password<<" "<<phone_number<<" "<<type<<""<<endl;

        User * u;

        if(type == "admin")
        {
            u =  new Admin (id, name, uname, phone_number, address, password);
        }
        else if(type == "student")
        {
            u =  new Student (id, name, uname, phone_number, address, password);
        }
        else if(type == "clerk")
        {
            u =  new Clerk (id, name, uname, phone_number, address, password);
        }

        library->add_User(u);
    }

    query.prepare("Select * from LibItems");
    query.exec();

    while(query.next())
    {
        cout<<"Loading Items"<<endl;

        int id = query.value(0).toInt();
        string name = query.value(1).toString().toStdString();
        string author = query.value(2).toString().toStdString();
        string subject = query.value(3).toString().toStdString();
        string category = query.value(4).toString().toStdString();
        string type = query.value(5).toString().toStdString();
        string item_state = query.value(6).toString().toStdString();

        cout<<id<<" "<<name<<" "<<author<<" "<<subject<<" "<<category<<" "<<type<<" "<<item_state<<endl;
        LibItem * i;

        state * in_state;

        if(item_state == "available")
        {
            in_state = obj->return_available();
        }
        else if(item_state == "unavailable")
        {
            in_state = obj->return_unavailable();
        }
        else if(item_state == "reference")
        {
            in_state = obj->return_reference();
        }
        else
        {
            in_state = obj->return_onHold();
        }

        if(type == "book")
        {
            i = new Book(id, name,author, subject, in_state);
        }
        else
        {
            i = new DVD(id, name, category, in_state);
        }

        library->add_LibItem(i);
    }


    query.prepare("select * from LoanItems");
    query.exec();

    while(query.next())
    {
         int id = query.value(0).toInt();
         int userid = query.value(1).toInt();
         int itemid = query.value(2).toInt();
         string iDate = query.value(3).toString().toStdString();
         string rDate = query.value(4).toString().toStdString();
         bool returned = query.value(5).toBool();

         if(returned)
             cout<<"returned"<<endl;
         else
             cout<<"not returned"<<endl;

         cout<<id<<" "<<userid<<" "<<itemid<<" "<<iDate<<" "<<rDate;

         User * temp_u = library->search_User(userid);
         LibItem * temp_i = library->search_LibItem(itemid);

         if(temp_u != nullptr && temp_i != nullptr)
         {
            LoanItem * l = new LoanItem(temp_u,temp_i, id, iDate, rDate, returned);
         }
    }
}
void create_connection()
{
    QSqlDatabase DB;
    DB=QSqlDatabase::addDatabase("QODBC");
    DB.setConnectOptions();
    DB.setDatabaseName("DRIVER={SQL Server};Server=DARLIK\\SQLEXPRESS;Database=LMS;Trusted_connection=yes;");

    if(DB.open())
    {
        cout<<"Database connected."<<endl;
    }
    else
        cout<<"Error in connecting database."<<endl;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    create_connection();
    load_data();
    loginMainWIndow * w =  new loginMainWIndow();
    w->show();
    return a.exec();
}


