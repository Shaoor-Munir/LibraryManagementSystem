#ifndef ISSUEITEM_H
#define ISSUEITEM_H

#include <QMainWindow>
#include"lms.h"
#include"lms_s.h"
#include"user.h"
#include"book.h"
#include"loanitem.h"
#include"libitem.h"
#include"dvd.h"

namespace Ui {
class IssueItem;
}

class IssueItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit IssueItem(QWidget *parent = 0);
    ~IssueItem();

private slots:
    void on_userID_search_button_clicked();

    void on_itemID_search_button_clicked();

    void on_issue_button_clicked();

private:
    Ui::IssueItem *ui;
    User * current_user;
    LibItem * current_item;
    LMS *library;
    bool itemAavailable;
    bool onHold;

};

#endif // ISSUEITEM_H
