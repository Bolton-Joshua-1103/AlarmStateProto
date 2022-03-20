#pragma once
#include "State_Base_Handler.h"

class PendingArmed : public State_Base_Handler
{
public:
   PendingArmed(ControllerCallBack& _call_back)
      : State_Base_Handler(state_enum::pending_alarm, _call_back) {}

   void receivedPassword() override {
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state
   void timeExpired() override {
      call_back.setHandler(state_enum::armed);
   }; // Will return Armed_state ref
   void printStateInfo() {
      std::cout << "***Alarm is being armed. 30 seconds until sensor is active.***" << std::endl;
   };
};

