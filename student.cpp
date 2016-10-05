#include "student.h"

Student::Student(string name, string uname, string password):User(name, uname, password)
{

}

string Student::return_type()
{
    return "user";
}
