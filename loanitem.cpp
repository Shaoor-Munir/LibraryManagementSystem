#include "loanitem.h"

#include"User.h"
#include"LibItem.h"

LoanItem::LoanItem(User * u, LibItem * item, int id, string iDate, string rDate, bool isReturned)
{
    this->id = id;
    this->u = u;
    this->item = item;
    this->u->add_loanItem(this);
    this->item->add_loanItem(this);
    this->iDate = iDate;
    this->rDate = rDate;
    this->isReturned = isReturned;
}

void LoanItem::returnItem(string rDate)
{
    this->isReturned = true;
    this->rDate = rDate;
}

bool LoanItem::check_status()
{
    return isReturned;
}
int LoanItem::get_id()
{
    return this->id;
}

User * LoanItem::get_user()
{
    return this->u;
}

LibItem * LoanItem::get_item()
{
    return this->item;
}
string LoanItem::return_iDate()
{
    return this->iDate;
}
string LoanItem::return_rDate()
{
    return this->rDate;
}
void LoanItem::remove_from_item()
{
    item->remove_loan_by_id(this->id, false);
}
void LoanItem::remove_from_user()
{
    u->remove_loan_by_id(this->id, false);
}
void LoanItem::renew_loan(string iDate)
{
    this->iDate = iDate;
}
