#ifndef LMS_S_H
#define LMS_S_H

#include"lms.h"
#include"user.h"
class state;
class LMS_S
{

    static LMS * library;
    static User * logged_user;
    static state * available;
    static state * unavailable;
    static state * reference;
    static state * onHold;

public:
    LMS_S();
    LMS * return_library();
    User *return_logged_user();
    void add_logged_user(User * in);
    state * return_available();
    state * return_unavailable();
    state * return_reference();
    state * return_onHold();
};

#endif // LMS_S_H
