#ifndef CLERK_H
#define CLERK_H

#include<iostream>
#include<vector>
#include<string>
#include"User.h"

using namespace std;

class LoanItem;

class Clerk : public User {


public:
    Clerk(int id = 0, string name = "",string uname = "", string phone_number = "", string address = "", string password = "");
    string return_type();

};

#endif // CLERK_H
