#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();

private slots:
    void on_in_type_currentIndexChanged();

    void on_buttonBox_accepted();

private:
    Ui::AddItem *ui;
};

#endif // ADDITEM_H
