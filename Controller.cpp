#include "Controller.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

Controller::Controller() {
   state_map.insert({ state_enum::disarmed, &disarmed_handler });
   state_map.insert({ state_enum::pending_armed, &pending_armed_handler });
   state_map.insert({ state_enum::armed, &armed_handler });
   state_map.insert({ state_enum::pending_alarm, &pending_alarm_handler });
   state_map.insert({ state_enum::alarm, &alarm_handler });

   current_state_handler = state_map.find(state_enum::disarmed)->second; //Starting in the disarmed state.
}

void Controller::PrintCurrentState() {
   current_state_handler->printStateInfo();
}

std::string Controller::getCurrentState()
{
   return to_string(current_state_handler->enum_name);
}

void Controller::receivedMotion() {
   current_state_handler->receivedMotion();
}

void Controller::receivedPassword() {
   current_state_handler->receivedPassword();
}

void Controller::heartBeat() {
   std::cout << "Current state: " << to_string(current_state_handler->enum_name) << endl;
   std::cout << "Current stopwatch: " << stopwatch << std::endl;
   current_state_handler->heartBeat();
}

void Controller::setHandler(state_enum new_state_enum) {
   if (state_map.find(new_state_enum)->second == current_state_handler) {
      cout << "No State Change..." << endl;
   }
   else {
      current_state_handler = state_map.find(new_state_enum)->second; //Assign current state to new desired state
   };
}

void Controller::soundHorn(bool sound_on)
{
   if (sound_on) {
      std::cout << "THERE IS AN INTRUDER IN THE STORE I'M CALLING 911" << endl;
   }
   else {
      std::cout << "All is quiet" << std::endl;
   }
}

Stopwatch& Controller::getStopwatch()
{
   return stopwatch;
}
