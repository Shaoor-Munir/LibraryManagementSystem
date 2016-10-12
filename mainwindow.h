#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_add_user_button_clicked();

    void on_add_item_button_clicked();

    void on_user_details_button_clicked();

    void on_view_loans_button_clicked();

    void on_issue_item_button_clicked();

    void on_search_item_clicked();

    void on_edit_user_button_clicked();

    void on_edit_item_button_clicked();

    void on_remove_loan_button_clicked();

    void on_logout_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
