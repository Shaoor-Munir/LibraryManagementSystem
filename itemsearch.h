#ifndef ITEMSEARCH_H
#define ITEMSEARCH_H

#include <QMainWindow>
#include"qsignalmapper.h"
namespace Ui {
class ItemSearch;
}

class ItemSearch : public QMainWindow
{
    Q_OBJECT

public:
    explicit ItemSearch(QWidget *parent = 0);
    ~ItemSearch();

    QSignalMapper ButtonSignalMapper;

    private slots:
    void CellButtonClicked(int itemID);


    void on_item_choice_currentIndexChanged(const QString &arg1);

    void on_search_options_currentIndexChanged(const QString &arg1);

    void on_search_button_clicked();

private:
    Ui::ItemSearch *ui;
};

#endif // ITEMSEARCH_H
