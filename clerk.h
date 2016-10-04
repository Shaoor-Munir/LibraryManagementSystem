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
    Clerk(string name = "");
    string return_type();

};

#endif // CLERK_H
