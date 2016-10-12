#ifndef REMOVELOAN_H
#define REMOVELOAN_H

#include <QMainWindow>
#include"loanitem.h"

namespace Ui {
class RemoveLoan;
}

class RemoveLoan : public QMainWindow
{
    Q_OBJECT

public:
    explicit RemoveLoan(QWidget *parent = 0);
    ~RemoveLoan();

private slots:
    void on_search_button_clicked();

    void on_check_in_button_clicked();

    void on_renew_button_clicked();

private:
    Ui::RemoveLoan *ui;
    LoanItem * loan;
};

#endif // REMOVELOAN_H
