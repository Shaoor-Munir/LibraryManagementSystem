#include "user.h"

#include"LoanItem.h"

User::User(string name, string uname)
{
    this->name = name;
    this->user_name = uname;
}

void User::add_loanItem(LoanItem * item)
{
    this->loans.push_back(item);
}

string User::get_username()
{
    return user_name;
}

string User::get_name()
{
    return name;
}

vector<LoanItem*> User::return_pending_loans()
{
    vector<LoanItem*> temp;

    for (int i = 0; i < loans.size(); i++)
    {
        if (!loans[i]->check_status())
            temp.push_back(loans[i]);
    }

    return temp;
}
