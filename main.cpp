#include <iostream>
#include "Controller.h"
#include "Framework.hpp"
#include "main.h"

using namespace std;

Controller state_controller{};

void alarmHeartBeat() {
   //cout << "...heart beat..." << endl;
   state_controller.heartBeat();
}

 void alarmCmd(char c)
{
      std::cout << "Before Command: " << state_controller.getCurrentState() << endl;

      switch (c) {

      case ('m'):
         cout << "Simulating Motion Detected" << endl;
         state_controller.receivedMotion();
         break;

      case('p'):
         cout << "Simulating Password Entered Correctly" << endl;
         state_controller.receivedPassword();
         break;

      case ('q'):
         cout << "Quitting! Thank you!" << endl;
         Framework::stopFramework(); // Is this what I do?
         break;
      }
      std::cout << "After Command: " << state_controller.getCurrentState() << endl;
}
int main() {
   Framework::setKeyHandler(alarmCmd);
   Framework::setHeartBeatHandler(alarmHeartBeat);
   Framework::startFramework();
}

