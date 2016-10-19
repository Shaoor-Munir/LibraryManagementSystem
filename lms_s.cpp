#include "lms_s.h"
#include "state.h"
#include"availablestate.h"
#include"unavailablestate.h"
#include"onholdstate.h"
#include"referencestate.h"

LMS* LMS_S::library  = new LMS();
User * LMS_S::logged_user = nullptr;
state * LMS_S::available = new availableState();
state * LMS_S::unavailable = new unavailableState();
state * LMS_S::reference = new referenceState();
state * LMS_S::onHold = new onHoldState();

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
state * LMS_S::return_available()
{
    return this->available;
}

state * LMS_S::return_unavailable()
{
    return this->unavailable;
}

state * LMS_S::return_reference()
{
    return this->reference;
}

state * LMS_S::return_onHold()
{
    return this->onHold;
}
