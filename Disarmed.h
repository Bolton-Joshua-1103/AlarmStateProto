#pragma once
#include "State_Base_Handler.h"

class Disarmed : public State_Base_Handler
{
public:
   Disarmed(IControllerCallBack& _call_back) 
      : State_Base_Handler(state_enum::disarmed, _call_back) {}

   void receivedPassword() override {
      Stopwatch& stopwatch = call_back.getStopwatch();
      stopwatch.reset();
      stopwatch.start();
      call_back.setHandler(state_enum::pending_armed);
   }; //If we received the password we're trying to arm the alarm (see state diagram)
   void printStateInfo() {
      std::cout << "***Alarm is disarmed.***" << std::endl;
   };
};

