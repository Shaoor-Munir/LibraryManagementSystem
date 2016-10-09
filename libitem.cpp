#include "libitem.h"
#include"loanitem.h"

LibItem::LibItem(int id, string name)
{
    this->id = id;
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

int LibItem::get_id()
{
   return this->id;
}

bool LibItem::check_availability()
{
    for(int i=0;i<loans.size();i++)
    {
        if(loans[i]->check_status() == false)
        {
            return false;
        }
    }
    return true;
}
