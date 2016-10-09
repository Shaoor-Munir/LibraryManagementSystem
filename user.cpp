#include "user.h"

#include"LoanItem.h"

User::User(int id, string name, string uname, string phone_number, string address, string password)
{
    this->id = id;
    this->name = name;
    this->user_name = uname;
    this->phone_number = phone_number;
    this->address = address;
    this->password = password;
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

string User::get_password()
{
    return this->password;
}

string User::get_address()
{
    return this->address;
}

string User::get_number()
{
    return this->phone_number;
}

int User::get_id()
{
    return id;
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
vector<LoanItem *> User::return_loans()
{
    return this->loans;
}
