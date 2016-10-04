#include "book.h"

Book::Book(string name, string author):LibItem(name)
{
    this->author = author;
}

string Book::get_author()
{
    return this->author;
}

string Book::return_type()
{
    return "book";
}
