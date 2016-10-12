#include "book.h"

Book::Book(int id, string name, string author, string subject):LibItem(id, name)
{
    this->author = author;
    this->subject = subject;
}

string Book::get_author()
{
    return this->author;
}

string Book::get_subject()
{
    return this->subject;
}

string Book::return_type()
{
    return "book";
}
void:: Book::update_info(string name, string author, string subject)
{
    this->name = name;
    this->author = author;
    this->subject = subject;
}
