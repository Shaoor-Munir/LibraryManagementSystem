#ifndef ADMIN_H
#define ADMIN_H


#include<iostream>
#include<vector>
#include<string>
#include"User.h"

using namespace std;

class LoanItem;

class Admin :public User {


public:
    Admin(int id = 0, string name = "",string uname = "", string phone_number = "", string address = "", string password = "");
    string return_type();
};

#endif // ADMIN_H
