#ifndef BOOK_H
#define BOOK_H

#include<iostream>
#include<vector>
#include<string>
#include"LibItem.h"

using namespace std;

class Book : public LibItem {
    string author;

public:
    Book(string name = "", string author = "");
    string get_author();
    string return_type();
};

#endif // BOOK_H
