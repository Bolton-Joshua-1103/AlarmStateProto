#pragma once
#include "state_handler_defs.h"
#include "ControllerCallBack.h"
#include <iostream>

class State_Base_Handler {
public:

   state_enum enum_name{ state_enum::disarmed };
   ControllerCallBack& call_back;
   State_Base_Handler(state_enum enum_state, ControllerCallBack& _call_back)
      : call_back(_call_back)
   {
      enum_name = enum_state;
   }
   // maybe can get rid of call_back calls
   virtual void receivedMotion() { call_back.setHandler(enum_name); }; //Will return the current state in the base class
   virtual void receivedPassword() { call_back.setHandler(enum_name); }; //Will return the current state in the base class
   virtual void timeExpired() { call_back.setHandler(enum_name); }; //Will return the current state in the base class

   virtual void printStateInfo() = 0;
};
