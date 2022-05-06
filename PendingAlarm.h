#pragma once
#include "State_Base_Handler.h"

class PendingAlarm : public State_Base_Handler
{
   public:
   PendingAlarm(IControllerCallBack& _call_back) 
      : State_Base_Handler(state_enum::pending_alarm, _call_back) {}

   void receivedPassword() override {
      Stopwatch& stopwatch = call_back.getStopwatch();
      stopwatch.stop();
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state ref

   void heartBeat() {
      Stopwatch& stopwatch = call_back.getStopwatch();
      if (stopwatch.elapsed() > expiration_time) {
         stopwatch.stop();
         call_back.soundHorn(true);
         call_back.setHandler(state_enum::alarm);
      }
   };

   void printStateInfo() {
      std::cout << "***Alarm will sound in " << expiration_time << " seconds...***" << std::endl;
   };
};

