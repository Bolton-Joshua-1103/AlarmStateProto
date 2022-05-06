#pragma once
#include "State_Base_Handler.h"

class PendingArmed : public State_Base_Handler
{
public:
   PendingArmed(IControllerCallBack& _call_back)
      : State_Base_Handler(state_enum::pending_armed, _call_back) {}

   void receivedPassword() override {
      Stopwatch& stopwatch = call_back.getStopwatch();
      stopwatch.stop();
      stopwatch.reset();//Might not need.
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state

   void heartBeat() override {
      Stopwatch& stopwatch = call_back.getStopwatch();
      if (stopwatch.elapsed() > expiration_time) {
         stopwatch.stop();
         call_back.setHandler(state_enum::armed);
      }
   };
   void printStateInfo() {
      std::cout << "***Alarm is being armed. " << expiration_time << " seconds until sensor is active.***" << std::endl;
   };
};

