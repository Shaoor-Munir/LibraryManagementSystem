#include "dvd.h"

DVD::DVD(int id, string name, string genre):LibItem(id, name)
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
