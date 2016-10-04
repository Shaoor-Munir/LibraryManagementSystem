#include "admin.h"

Admin::Admin(string name):User(name)
{
}

string Admin::return_type()
{
    return "admin";
}
