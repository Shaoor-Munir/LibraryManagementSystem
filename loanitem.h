#ifndef LOANITEM_H
#define LOANITEM_H

#include<iostream>
#include<string>
#include<vector>
#include<ctime>

using namespace std;

class LibItem;
class User;

class LoanItem {
    int id;
    User * u;
    LibItem * item;
    string iDate;
    string rDate;
    bool isReturned;
public:
    LoanItem(User *u = nullptr, LibItem *item = nullptr, int id = 0, string iDate = "", string rDate = "",  bool isReturned = false);
    void returnItem(string rDate);
    bool check_status();
    int get_id();
    string return_iDate();
    string return_rDate();
    User * get_user();
    LibItem * get_item();
    void remove_from_item();
    void remove_from_user();
    void renew_loan(string iDate);
};
#endif // LOANITEM_H
