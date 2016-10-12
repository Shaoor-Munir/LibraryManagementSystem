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
void User::update_info(string name, string uname, string address, string phoneNumber, string password)
{
    this->name = name;
    this->user_name = uname;
    this->address = address;
    this->phone_number = phoneNumber;
    this->password = password;
}

bool User::remove_loan_by_id(int loanID, bool self_call)
{
    LoanItem *l;
    for(int i=0;i<loans.size(); i++)
    {
        if(loans[i]->get_id() == loanID)
        {

            l = loans[i];
            if(self_call)
            {
                loans[i]->remove_from_item();
                delete l;
            }
            loans.erase(loans.begin()+i);
            return true;
        }
    }
    return false;
}

void User::delete_all_loans()
{

    for(int i=0;i<loans.size();i++)
    {
        remove_loan_by_id(loans[i]->get_id());
    }
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

void User::return_item(int loanID)
{
    for(int i=0;i<loans.size(); i++)
    {
        if(loans[i]->get_id() == loanID)
        {
           // loans[i]->returnItem();
            return;
        }
    }
}
