#include <iostream>
#include "Controller.h"

using namespace std;

void printOptionMenu() {
   cout << endl;
   cout << "-------------------" << endl;
   cout << "Enter 'm' to simulate motion." << endl;
   cout << "Enter 'p' to simulate password entry." << endl;
   cout << "Enter 't' to simulate 30 seconds pasing." << endl;
   cout << "Enter 'q' to exit program." << endl;
   cout << "-------------------" << endl;
   cout << endl;
}

int main() {
   Controller state_controller{};
   char c{};
   while (c != 'q') {
      printOptionMenu();
      state_controller.PrintCurrentState();
      cin >> c;

      switch (c) {
      case ('m'):
         cout << "Simulating Motion Detected" << endl;
         state_controller.receivedMotion();
         break;

      case('p'):
         cout << "Simulating Password Entered Correctly" << endl;
         state_controller.receivedPassword();
         break;

      case ('t'):
         cout << "Simulating 30 seconds passing" << endl;
         state_controller.timeExpired();
         break;

      case ('q'):
         cout << "Quitting! Thank you!" << endl;
         break;
      }
   }
}
