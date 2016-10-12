#include "userloans.h"
#include "ui_userloans.h"
#include"QStandardItemModel"
#include"user.h"
#include"lms_s.h"
#include"loanitem.h"
#include"lms_s.h"
#include"libitem.h"
#include"qpushbutton.h"

UserLoans::UserLoans(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserLoans)
{
    ui->setupUi(this);
    QStandardItemModel * model = new QStandardItemModel();





    model->setHorizontalHeaderItem(0, new QStandardItem("Item Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Issue Date"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Return Date"));

    ui->loans->setModel(model);

   LMS_S * obj = new LMS_S;
   User * u = obj->return_logged_user();

   vector<LoanItem *> loanitems = u->return_loans();

   cout<<loanitems.size()<<endl;

   for(int i=0;i< loanitems.size();i++)
   {
       QStandardItem *data = new QStandardItem(QString::fromStdString((loanitems[i]->get_item())->get_name()));
       model->setItem(i, 0, data);

       data = new QStandardItem(QString::fromStdString(loanitems[i]->return_iDate()));
       model->setItem(i, 1, data);

       QString returnStatus = QString::fromStdString(loanitems[i]->return_rDate());
       if(returnStatus == "")
           returnStatus = "Item not returned";
       data = new QStandardItem(returnStatus);
       model->setItem(i, 2, data);

   }

   ui->loans->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   ui->loans->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

UserLoans::~UserLoans()
{
    delete ui;
}

void UserLoans::on_loans_doubleClicked(const QModelIndex &index)
{


}
