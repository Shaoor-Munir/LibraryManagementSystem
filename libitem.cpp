#include "libitem.h"
#include"loanitem.h"
#include"lms_s.h"
#include"user.h"
#include"state.h"

LibItem::LibItem(int id, string name, state *in_state)
{
    this->id = id;
    this->name = name;

    LMS_S * obj =  new LMS_S();
    this->itemState = in_state;
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

string LibItem::check_availability()
{
    return this->itemState->return_state();
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

void LibItem::issueBook(User *user)
{
    this->itemState->issueBook(this, user);
}

void LibItem::set_state(state *in_state)
{
    this->itemState = in_state;
}
