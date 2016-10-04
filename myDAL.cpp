#include "mydal.h"

myDAL::myDAL()
{
    QSqlDatabase DB;
    DB=QSqlDatabase::addDatabase("QODBC");
    DB.setConnectOptions();
    DB.setDatabaseName("DRIVER={SQL Server};Server=DARLIK\SQLEXPRESS;Database=LMS;Trusted_connection=yes;");


//Provide Username & Password if required
    //DB.setUserName("username");
    //DB.setPassword("password");

    if(!DB.open()){
        qDebug("Error");
    }
    else{
        qDebug("Connected");
    }

}
