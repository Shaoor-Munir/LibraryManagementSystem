#include "clerk.h"


Clerk::Clerk(int id, string name, string uname,string phone_number, string address, string password):User(id, name, uname,phone_number, address, password)
{
}

string Clerk::return_type()
{
    return "clerk";
}
