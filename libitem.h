#ifndef LIBITEM_H
#define LIBITEM_H


#include<iostream>
#include<vector>
#include<string>


using namespace std;

class LoanItem;

class LibItem {

protected:
    int id;
    string name;
    vector <LoanItem*> loans;

public:
    LibItem(int id = 0, string name = "");
    void add_loanItem(LoanItem *item);
    string get_name();
    int get_id();
    virtual string return_type() = 0;
    bool check_availability();
    bool remove_loan_by_id(int loanID, bool self_call = true);
    void delete_all_loans();

};

#endif // LIBITEM_H
