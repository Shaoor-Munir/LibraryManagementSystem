#ifndef USERLOANS_H
#define USERLOANS_H

#include <QMainWindow>

namespace Ui {
class UserLoans;
}

class UserLoans : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserLoans(QWidget *parent = 0);
    ~UserLoans();

private slots:

    void on_loans_doubleClicked(const QModelIndex &index);

private:
    Ui::UserLoans *ui;
};

#endif // USERLOANS_H
