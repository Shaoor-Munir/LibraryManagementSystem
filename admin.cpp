#include "admin.h"

Admin::Admin(string name, string uname, string password):User(name, uname, password)
{

}

string Admin::return_type()
{
    return "admin";
}
