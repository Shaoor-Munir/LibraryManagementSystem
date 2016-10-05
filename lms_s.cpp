#include "lms_s.h"

LMS* LMS_S::library  = new LMS();
User * LMS_S::logged_user = nullptr;

LMS_S::LMS_S()
{
}

LMS * LMS_S::return_library()
{
    return this->library;
}

User * LMS_S::return_logged_user()
{
    return this->logged_user;
}

void LMS_S::add_logged_user(User *in)
{
    this->logged_user = in;
}
