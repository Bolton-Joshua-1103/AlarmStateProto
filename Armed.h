#pragma once
#include "State_Base_Handler.h"

class Armed : public State_Base_Handler {
public:
   Armed(IControllerCallBack& _call_back) 
      : State_Base_Handler(state_enum::armed, _call_back) {}

   void receivedPassword() override {
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state ref

   void receivedMotion() override {
      Stopwatch& stopwatch = call_back.getStopwatch();
      stopwatch.reset();
      stopwatch.start();
      call_back.setHandler(state_enum::pending_alarm);
   }; // Will return Pending_Alarm ref
   void printStateInfo() override {
      std::cout << "***Alarm is armed. Detecting Motion...***" << std::endl;
   };
};

