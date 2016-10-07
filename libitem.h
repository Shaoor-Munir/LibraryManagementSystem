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

};

#endif // LIBITEM_H
