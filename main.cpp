#include <iostream>
#include "Controller.h"

using namespace std;

void printOptionMenu() {
   cout << endl;
   cout << "-------------------" << endl;
   cout << "Enter 'm' to simulate motion." << endl;
   cout << "Enter 'p' to simulate password entry." << endl;
   cout << "Enter 'h' to heartbeat." << endl;
   cout << "Enter 'q' to exit program." << endl;
   cout << "-------------------" << endl;
   cout << endl;
}

int main() {
   Controller state_controller{};
   char c{};
   while (c != 'q') {
      printOptionMenu();
      //state_controller.PrintCurrentState();
      cin >> c;
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
      case('h'):
          cout << "Heartbeat occurred." << endl;
          state_controller.heartBeat();
          break;
      case ('q'):
         cout << "Quitting! Thank you!" << endl;
         break;
      }
      std::cout << "After Command: " << state_controller.getCurrentState() << endl;
   }
}
