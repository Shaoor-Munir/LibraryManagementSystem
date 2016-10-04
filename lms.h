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

class LMS {
    vector <LibItem*> items;
    vector <User*> users;

public:
    LMS();
    void add_LibItem(LibItem *item);
    bool add_User(User *user);
    LibItem * search_LibItem(string type, string name);
    User * search_User(string type, string username);
    vector <User *> search_user_by_name(string type, string name);
    vector <Book *>author_search_book(string author);
    vector <DVD *>category_search_dvd(string category);
    bool remove_LibItem(LibItem * in);
    bool remove_user(string username);

};

#endif // LMS_H
