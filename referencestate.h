#ifndef REFERENCESTATE_H
#define REFERENCESTATE_H

#include"state.h"

class referenceState : public state
{
public:
    referenceState();
    void issueBook(LibItem * item, User * user);
    string return_state();
};

#endif // REFERENCESTATE_H
