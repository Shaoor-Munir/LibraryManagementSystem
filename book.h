#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<vector>
#include<string>
#include"LibItem.h"

using namespace std;

class Book : public LibItem {
    string author;
    string subject;

public:
    Book(int id = 0, string name = "", string author = "", string subject = "");
    string get_author();
    string get_subject();
    string return_type();
};

#endif // BOOK_H
