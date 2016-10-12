#ifndef EDITUSER_H
#define EDITUSER_H

#include <QMainWindow>
#include"user.h"

namespace Ui {
class EditUser;
}

class EditUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditUser(QWidget *parent = 0);
    ~EditUser();

private slots:
    void on_search_button_clicked();

    void on_delete_button_clicked();

    void on_update_button_clicked();

private:
    Ui::EditUser *ui;
    User *u;
};

#endif // EDITUSER_H
