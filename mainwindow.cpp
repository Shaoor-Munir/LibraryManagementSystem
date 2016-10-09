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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LMS_S *obj = new LMS_S();

    User * curr_user = obj->return_logged_user();

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
