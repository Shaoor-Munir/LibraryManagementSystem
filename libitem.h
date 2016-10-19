#ifndef LIBITEM_H
#define LIBITEM_H


#include<iostream>
#include<vector>
#include<string>

class User;
class state;

using namespace std;

class LoanItem;

class LibItem {

protected:
    int id;
    string name;
    vector <LoanItem*> loans;
    state * itemState;

public:
    LibItem(int id = 0, string name = "", state*  in_state = nullptr);
    void add_loanItem(LoanItem *item);
    string get_name();
    int get_id();
    void set_state(state * in_state);
    void issueBook(User *user);
    virtual string return_type() = 0;
    string check_availability();
    bool remove_loan_by_id(int loanID, bool self_call = true);
    void delete_all_loans();

};

#endif // LIBITEM_H
