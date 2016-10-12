#ifndef EDITITEM_H
#define EDITITEM_H

#include <QMainWindow>
#include"libitem.h"
#include"book.h"
#include"dvd.h"

namespace Ui {
class EditItem;
}

class EditItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditItem(QWidget *parent = 0);
    ~EditItem();

private slots:
    void on_search_button_clicked();

    void on_delete_button_clicked();

    void on_update_button_clicked();

private:
    Ui::EditItem *ui;
    LibItem * item;
};

#endif // EDITITEM_H
