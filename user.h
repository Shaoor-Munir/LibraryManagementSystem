#ifndef USER_H
#define USER_H


#include<iostream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class LoanItem;

class User {

protected:
    string name;
    string user_name;
    vector <LoanItem *> loans;

public:
    User(string name ="", string uname="");
    void add_loanItem(LoanItem *item);
    string get_username();
    string get_name();
    virtual string return_type() = 0;
    vector<LoanItem *> return_pending_loans();
};

#endif // USER_H
