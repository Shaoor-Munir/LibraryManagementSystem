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
    Admin(string name);
    string return_type();
};

#endif // ADMIN_H
