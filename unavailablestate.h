#ifndef UNAVAILABLESTATE_H
#define UNAVAILABLESTATE_H

#include"state.h"

class unavailableState: public state
{
public:
    unavailableState();
    void issueBook(LibItem * item, User * user);
    string return_state();
};

#endif // UNAVAILABLESTATE_H
