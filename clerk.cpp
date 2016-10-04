#include "clerk.h"


Clerk::Clerk(string name):User(name)
{
}

string Clerk::return_type()
{
    return "clerk";
}
