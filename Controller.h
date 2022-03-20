#pragma once
#include "PendingAlarm.h"
#include "Armed.h"
#include "PendingArmed.h"
#include "Alarm.h"
#include "Disarmed.h"
#include "state_handler_defs.h"
#include "ControllerCallBack.h"
#include <map>


class Controller : ControllerCallBack {
public:

   Disarmed disarmed_handler{ *this };
   PendingArmed pending_armed_handler{ *this };
   Armed armed_handler{ *this };
   PendingAlarm pending_alarm_handler{ *this };
   Alarm alarm_handler{ *this };

   State_Base_Handler* current_state_handler{}; // This is the pointer that will be reassigned constantly (By each event(method) of the state(object)).
   std::map<state_enum, State_Base_Handler*> state_map;

   Controller();

   void PrintCurrentState();
   //void ChangeCurrentState(state_enum);


   void receivedMotion(); //Will Imitate the motion sensor sensing by calling: current_state_handler-> receivedMotion();
   void receivedPassword(); //Will imitate the password being entered correctly by calling: current_state_hand->receivedPassword();
   void timeExpired(); //Will imitate 30 seconds passing

   void setHandler(state_enum new_state_enum) override;
   void soundHorn(bool sound_on) override;
};

