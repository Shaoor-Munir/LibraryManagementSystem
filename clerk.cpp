#include "clerk.h"


Clerk::Clerk(string name, string uname, string password):User(name, uname, password)
{
}

string Clerk::return_type()
{
    return "clerk";
}
