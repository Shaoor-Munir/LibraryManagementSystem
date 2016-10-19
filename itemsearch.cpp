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

    QSqlQuery query;

    if(ui->item_choice->currentText() == "Book")
    {

        model->setHorizontalHeaderItem(0, new QStandardItem("Book ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Title"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Author"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Subject"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Availability Status"));
        model->setHorizontalHeaderItem(5, new QStandardItem("Put on Hold"));
        ui->searchResult->setModel(model);

        QString temp = ui->in_search_term->text();
        temp = "%"+temp+"%";

        if(ui->search_options->currentText() == "Title")
        {
            cout<<"searching by title"<<endl;
            query.prepare("select * from LibItems where iName like ? and itemType = 'book'");

            //result = library->name_search_libitem("book", ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Author")
        {

            query.prepare("select * from LibItems where author like ? and itemType = 'book'");
            //result = library->author_search_book(ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Subject")
        {

            query.prepare("select * from LibItems where bSubject like ? and itemType = 'book'");
            //result = library->subject_search_book(ui->in_search_term->text().toStdString());
        }
        query.bindValue(0, temp);
        query.exec();

        int i = 0;
        while(query.next())
        {
            cout<<query.value(0).toString().toStdString()<<endl;
            QStandardItem *data = new QStandardItem(query.value(0).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 0, data);

            data = new QStandardItem(query.value(1).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 1, data);


            data = new QStandardItem(query.value(2).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 2, data);


            data = new QStandardItem(query.value(3).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 3, data);


            data = new QStandardItem(query.value(6).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 4, data);

            if(query.value(6).toString() != "reference")
            {
                QPushButton* helpButton = new QPushButton("Put on Hold");
                ui->searchResult->setIndexWidget(model->index(i,5), helpButton);

                connect(helpButton, SIGNAL(clicked()), &ButtonSignalMapper, SLOT(map()));
                ButtonSignalMapper.setMapping(helpButton, query.value(0).toInt());
                connect(&ButtonSignalMapper, SIGNAL(mapped(int)), this, SLOT(CellButtonClicked(int)));

                //data = new QStandardItem("Item is loaned out");
            }
            i++;

        }
    }
    else
    {
        model->setHorizontalHeaderItem(0, new QStandardItem("DVD ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Title"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Category"));
        model->setHorizontalHeaderItem(3, new QStandardItem("Availability Status"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Put on Hold"));
        ui->searchResult->setModel(model);

        QString temp = ui->in_search_term->text();
        temp = "%"+temp+"%";

        if(ui->search_options->currentText() == "Title")
        {
            query.prepare("select * from LibItems where iName like ? and itemType = 'dvd'");
            //result = library->name_search_libitem("dvd", ui->in_search_term->text().toStdString());
        }
        else if(ui->search_options->currentText() == "Category")
        {

            query.prepare("select * from LibItems where category like ? and itemType = 'dvd'");
            //result = library->category_search_dvd(ui->in_search_term->text().toStdString());
        }

        query.bindValue(0, temp);
        query.exec();

        int i = 0;
        while(query.next())
        {
            QStandardItem *data = new QStandardItem(query.value(0).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 0, data);

            data = new QStandardItem(query.value(1).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 1, data);


            data = new QStandardItem(query.value(4).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i, 2, data);

            data = new QStandardItem(query.value(6).toString());
            data->setTextAlignment(Qt::AlignCenter);
            model->setItem(i,3, data);

            if(query.value(6).toString() != "reference")
            {
                QPushButton* helpButton = new QPushButton("Put on Hold");
                ui->searchResult->setIndexWidget(model->index(i,4), helpButton);

                connect(helpButton, SIGNAL(clicked()), &ButtonSignalMapper, SLOT(map()));
                ButtonSignalMapper.setMapping(helpButton, query.value(0).toInt());
                connect(&ButtonSignalMapper, SIGNAL(mapped(int)), this, SLOT(CellButtonClicked(int)));
            }

            i++;

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
