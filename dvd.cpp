#include "dvd.h"

DVD::DVD(string name, string genre):LibItem(name)
{
    this->category = genre;
}

string DVD::get_category()
{
    return this->category;
}

string DVD::return_type()
{
    return "dvd";
}
