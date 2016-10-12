#include "itemsearch.h"
#include "ui_itemsearch.h"
#include"QStandardItemModel"
#include"user.h"
#include"lms_s.h"
#include"dvd.h"
#include"book.h"
#include"loanitem.h"
#include"lms_s.h"
#include"libitem.h"
#include"qpushbutton.h"
#include<iostream>
#include"qmessagebox.h"
#include<QtSql/QSql>
#include<QtSql>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlError>
#include<QtCore>
using namespace std;

ItemSearch::ItemSearch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ItemSearch)
{
    ui->setupUi(this);
}

ItemSearch::~ItemSearch()
{
    delete ui;
}

void ItemSearch::on_item_choice_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Book")
    {
        ui->search_options->setItemText(1, "Author");
        ui->search_options->insertItem(2, "Subject");

    }
    else
    {
        ui->search_options->setItemText(1, "Category");
        ui->search_options->removeItem(2);
    }
}

void ItemSearch::on_search_options_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Title")
        ui->search_label->setText("Item Title:");
    else if(arg1 == "Author")
        ui->search_label->setText("Author's Name:");
    else if(arg1 == "Subject")
        ui->search_label->setText("Subject:");
    else if(arg1 == "Category")
        ui->search_label->setText("DVD Category:");
}

void ItemSearch::on_search_button_clicked()
{
    QStandardItemModel * model = new QStandardItemModel();

    LMS_S * obj = new LMS_S();
    LMS * library = obj->return_library();
    vector<LibItem *> result;

    if(ui->item_choice->currentText() == "Book")
    {

        model->setHorizontalHeaderItem(0, new QStandardItem("Book ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Title"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Author"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Subject"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Loan Status"));
        ui->searchResult->setModel(model);

        if(ui->search_options->currentText() == "Title")
        {
            result = library->name_search_libitem("book", ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Author")
        {
            result = library->author_search_book(ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Subject")
        {
            result = library->subject_search_book(ui->in_search_term->text().toStdString());
        }

        for(int i=0;i<result.size();i++)
        {
            QStandardItem *data = new QStandardItem(QString::number(result[i]->get_id()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 0, data);

            data = new QStandardItem(QString::fromStdString(result[i]->get_name()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 1, data);


            data = new QStandardItem(QString::fromStdString(((Book *)result[i])->get_author()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 2, data);


            data = new QStandardItem(QString::fromStdString(((Book *)result[i])->get_author()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 3, data);

            if(result[i]->check_availability() == false)
            {
                data = new QStandardItem("Item is available for loan");
                data->setTextAlignment(Qt::AlignCenter);
                model->setItem(i, 4, data);
            }
            else
            {
                QPushButton* helpButton = new QPushButton("Unavilable, put on hold");
                ui->searchResult->setIndexWidget(model->index(i,4), helpButton);

                connect(helpButton, SIGNAL(clicked()), &ButtonSignalMapper, SLOT(map()));
                ButtonSignalMapper.setMapping(helpButton, result[i]->get_id());
                connect(&ButtonSignalMapper, SIGNAL(mapped(int)), this, SLOT(CellButtonClicked(int)));


                //data = new QStandardItem("Item is loaned out");
            }


        }
    }
    else
    {
        model->setHorizontalHeaderItem(0, new QStandardItem("DVD ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Title"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Category"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Loan Status"));
        ui->searchResult->setModel(model);

        if(ui->search_options->currentText() == "Title")
        {
            result = library->name_search_libitem("dvd", ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Category")
        {
            result = library->category_search_dvd(ui->in_search_term->text().toStdString());
        }

        for(int i=0;i<result.size();i++)
        {
            QStandardItem *data = new QStandardItem(QString::number(result[i]->get_id()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 0, data);

            data = new QStandardItem(QString::fromStdString(result[i]->get_name()));
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 1, data);


            data = new QStandardItem(QString::fromStdString(((DVD *)result[i])->get_category()));

            data->setTextAlignment(Qt::AlignCenter);model->setItem(i, 2, data);

            if(result[i]->check_availability() == false)
            {
                data = new QStandardItem("Item available for loan");
            }
            else
            {
                data = new QStandardItem("Item is loaned out");
            }
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 3, data);

        }

    }

   ui->searchResult->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   ui->searchResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void ItemSearch::CellButtonClicked(int itemID)
{
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Put Item on Hold", "Are you sure you want to put this item on hold?", QMessageBox::Yes|QMessageBox::No);

      if (reply == QMessageBox::Yes)
      {
          LMS_S obj;
          User * u =obj.return_logged_user();
          QSqlQuery query;
          query.prepare("execute hold_item @input_userID=?, @input_itemId=?, @output_holdID=? output");
          query.bindValue(0, u->get_id());
          query.bindValue(1, itemID);
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
      else
      {
        qDebug() << "Yes was *not* clicked";
      }
}
