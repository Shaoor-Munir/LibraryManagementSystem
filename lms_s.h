#ifndef LMS_S_H
#define LMS_S_H

#include"lms.h"
#include"user.h"

class LMS_S
{

    static LMS * library;
    static User * logged_user;

public:
    LMS_S();
    LMS * return_library();
    User *return_logged_user();
    void add_logged_user(User * in);
};

#endif // LMS_S_H
