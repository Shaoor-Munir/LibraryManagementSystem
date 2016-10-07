#include "book.h"

Book::Book(int id, string name, string author):LibItem(id, name)
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
