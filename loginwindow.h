#ifndef LOGINMAINWINDOW_H
#define LOGINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class loginMainWIndow;
}

class loginMainWIndow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginMainWIndow(QWidget *parent = 0);
    ~loginMainWIndow();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::loginMainWIndow *ui;
};

#endif // LOGINMAINWINDOW_H
