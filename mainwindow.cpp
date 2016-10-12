#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lms_s.h"
#include"admin.h"
#include"student.h"
#include"QMessageBox"
#include"adduser.h"
#include"additem.h"
#include"userdetails.h"
#include"userloans.h"
#include"issueitem.h"
#include"itemsearch.h"
#include"edituser.h"
#include"edititem.h"
#include"removeloan.h"
#include"loginwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LMS_S *obj = new LMS_S();

    User * curr_user = obj->return_logged_user();


    if(curr_user->return_type() == "admin")
    {
        ui->MainWindowLabel->setText("Admin Menu");
    }
    else if(curr_user->return_type()=="clerk")
    {
        ui->MainWindowLabel->setText("Clerk Menu");
        ui->edit_item_button->hide();
        ui->edit_user_button->hide();
    }
    else
    {
        ui->MainWindowLabel->setText("Student Menu");
        ui->edit_item_button->hide();
        ui->edit_user_button->hide();
        ui->issue_item_button->hide();
        ui->add_item_button->hide();
        ui->add_user_button->hide();
        ui->remove_loan_button->hide();
        this->resize(800,300);
    }

    ui->NLabel->setText(QString::fromStdString(curr_user->get_name()));

    ui->UNLabel->setText(QString::fromStdString(curr_user->get_username()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_user_button_clicked()
{
    AddUser * add = new AddUser();
    add->show();
}

void MainWindow::on_add_item_button_clicked()
{
    AddItem * add = new AddItem();
    add->show();
}

void MainWindow::on_user_details_button_clicked()
{
    UserDetails * details =  new UserDetails(this);
    details->show();
}

void MainWindow::on_view_loans_button_clicked()
{
    UserLoans * loans =  new UserLoans();
    loans->show();
}

void MainWindow::on_issue_item_button_clicked()
{
    IssueItem * issue = new IssueItem();
    issue->show();
}

void MainWindow::on_search_item_clicked()
{
    ItemSearch * search = new ItemSearch();
    search->show();
}

void MainWindow::on_edit_user_button_clicked()
{
    EditUser * edit = new EditUser();
    edit->show();
}

void MainWindow::on_edit_item_button_clicked()
{
    EditItem* edit = new EditItem();
    edit->show();
}

void MainWindow::on_remove_loan_button_clicked()
{
    RemoveLoan * loan = new RemoveLoan();
    loan->show();
}

void MainWindow::on_logout_button_clicked()
{
    LMS_S obj;
    obj.add_logged_user(nullptr);
    loginMainWIndow * login = new loginMainWIndow();
    login->show();
    this->close();
}
