#ifndef LIBITEM_H
#define LIBITEM_H


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class LoanItem;

class LibItem {

protected:
    string name;
    vector <LoanItem*> loans;

public:
    LibItem(string name = "");
    void add_loanItem(LoanItem *item);
    string get_name();
    virtual string return_type() = 0;

};

#endif // LIBITEM_H
