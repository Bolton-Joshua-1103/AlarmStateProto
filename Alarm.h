#pragma once
#include "State_Base_Handler.h"

class Alarm : public State_Base_Handler
{
public:
   Alarm(ControllerCallBack& _call_back)
      : State_Base_Handler(state_enum::alarm, _call_back) {};

   void receivedPassword() override {
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state ref
   void printStateInfo() override {
      std::cout << "-----ALARM ACTIVE-----" << std::endl;
   };
};

