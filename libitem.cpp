#include "libitem.h"

LibItem::LibItem(string name)
{
    this->name = name;
}

void LibItem::add_loanItem(LoanItem * item)
{
    this->loans.push_back(item);
}

string LibItem::get_name()
{
    return this->name;
}
