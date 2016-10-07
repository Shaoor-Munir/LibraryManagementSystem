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
    LoanItem(User *u = nullptr, LibItem *item = nullptr, int id = 0, bool isReturned = false);
    void returnItem();
    bool check_status();
    User * get_user();
    LibItem * get_item();
};
#endif // LOANITEM_H
