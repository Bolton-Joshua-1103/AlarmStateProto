#pragma once
#include "State_Base_Handler.h"

class Alarm : public State_Base_Handler
{
public:
   Alarm(IControllerCallBack& _call_back)
      : State_Base_Handler(state_enum::alarm, _call_back) {};

   void receivedPassword() override {
      //std::cout << "Alarm has been turned off!" << std::endl;
      call_back.soundHorn(false);
      call_back.setHandler(state_enum::disarmed);
   }; // Will return disarmed_state ref
   void printStateInfo() override {
      std::cout << "-----ALARM ACTIVE-----" << std::endl;
   };
};

