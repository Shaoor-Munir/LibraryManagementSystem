#ifndef ONHOLDSTATE_H
#define ONHOLDSTATE_H

#include"state.h"

class onHoldState : public state
{
public:
    onHoldState();
    void issueBook(LibItem * item, User * user);
    string return_state();
};

#endif // ONHOLDSTATE_H
