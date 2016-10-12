#ifndef LMS_H
#define LMS_H

#include<iostream>
#include<vector>

using namespace std;

class LibItem;
class Book;
class DVD;
class User;
class Student;
class Admin;
class Clerk;
class LoanItem;

class LMS {
    vector <LibItem*> items;
    vector <User*> users;

public:
    LMS();
    void add_LibItem(LibItem *item);
    bool add_User(User *user);
    LibItem * search_LibItem(int id);
    User * login_user (string uname, string password);
    User * search_User(int id);
    void add_existing_loan(LoanItem *in);
    vector <User *> search_user_by_name(string type, string name);
    vector<LibItem *> name_search_libitem(string type, string in_name);
    vector <LibItem *>author_search_book(string author);
    vector<LibItem *>subject_search_book(string subject);
    vector <LibItem *>category_search_dvd(string category);
    bool remove_LibItem(int id);
    bool remove_user(int id);
    bool remove_user_loans();
    bool check_username(string uname, User *u);

};

#endif // LMS_H
