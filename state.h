#ifndef STATE_H
#define STATE_H

#include"user.h"
#include"libitem.h"

class state
{
public:
    state();
    virtual void issueBook(LibItem * item, User * user)=0;
    virtual string return_state()=0;
};

#endif // STATE_H
