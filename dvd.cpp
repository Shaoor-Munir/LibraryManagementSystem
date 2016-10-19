#include "dvd.h"

DVD::DVD(int id, string name, string genre, state *in_state):LibItem(id, name, in_state)
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
void DVD::update_info(string name, string category)
{
    this->name = name;
    this->category = category;
}
