#include "student.h"

Student::Student(int id, string name, string uname,string phone_number, string address, string password):User(id, name, uname,phone_number, address, password)
{

}

string Student::return_type()
{
    return "user";
}
