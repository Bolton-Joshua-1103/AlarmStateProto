#pragma once
#include "state_handler_defs.h"
#include "Stopwatch.h"

struct IControllerCallBack
{
   virtual void setHandler(state_enum my_enum) = 0;
   virtual void soundHorn(bool sound_on) = 0;
   virtual Stopwatch& getStopwatch() = 0;
};
