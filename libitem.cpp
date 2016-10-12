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
bool LibItem::remove_loan_by_id(int loanID, bool self_call)
{
    LoanItem *l;
    for(int i=0;i<loans.size(); i++)
    {
        if(loans[i]->get_id() == loanID)
        {

            l = loans[i];
            if(self_call)
            {
                loans[i]->remove_from_user();
                delete l;
            }
            loans.erase(loans.begin()+i);
            return true;
        }
    }
    return false;
}

void LibItem:: delete_all_loans()
{

    for(int i=0;i<loans.size();i++)
    {
        remove_loan_by_id(loans[i]->get_id());
    }
}
