#include "admin.h"

Admin::Admin(int id, string name, string uname,string phone_number, string address, string password):User(id, name, uname,phone_number, address, password)
{

}

string Admin::return_type()
{
    return "admin";
}
