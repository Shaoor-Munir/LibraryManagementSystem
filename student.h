#ifndef STUDENT_H
#define STUDENT_H


#include<iostream>
#include<vector>
#include<string>
#include"User.h"

using namespace std;

class LoanItem;

class Student : public User {


public:
    Student(int id = 0, string name = "",string uname = "", string phone_number = "", string address = "", string password = "");
    string return_type();
};
#endif // STUDENT_H
