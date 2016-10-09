#ifndef USERDETAILS_H
#define USERDETAILS_H

#include <QMainWindow>

namespace Ui {
class UserDetails;
}

class UserDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserDetails(QWidget *parent = 0);
    ~UserDetails();

private:
    Ui::UserDetails *ui;
};

#endif // USERDETAILS_H
