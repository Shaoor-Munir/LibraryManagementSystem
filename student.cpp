#include "student.h"

Student::Student(string name, string uname):User(name, uname)
{

}

string Student::return_type()
{
    return "user";
}
