#pragma once
#include "State_Base_Handler.h"

class PendingAlarm : public State_Base_Handler
{
   public:
   PendingAlarm(ControllerCallBack& _call_back) 
      : State_Base_Handler(state_enum::pending_alarm, _call_back) {}

   void receivedPassword() override {
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state ref
   void timeExpired() override {
      call_back.setHandler(state_enum::alarm);
   }; // Will return alarm_state ref
   void printStateInfo() {
      std::cout << "***Alarm will sound in 30 seconds...***" << std::endl;
   };
};

