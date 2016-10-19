#ifndef AVAILABLESTATE_H
#define AVAILABLESTATE_H
#include"state.h"

class availableState : public state
{
public:
    availableState();
    void issueBook(LibItem * item, User * user);
    string return_state();
};

#endif // AVAILABLESTATE_H
