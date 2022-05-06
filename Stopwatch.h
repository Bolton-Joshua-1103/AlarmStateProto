#pragma once
#include <chrono>
#include <iostream>


using namespace std::chrono_literals;


class Stopwatch {
public:
   using Resolution = std::chrono::duration<double>;


   bool start() {
      if (running) return false; // don't initialize start.
      else {
         start_time = std::chrono::steady_clock::now();
         running = true;
         return true;
      }
   }

   bool stop() {
      if (!running) return false; // can't stop something that isn't running
      else {
         prev_running_time += std::chrono::steady_clock::now() - start_time;
         running = false;
         return true;
      }
   }

   Resolution elapsed() const {
      if (running) {
         return (prev_running_time + std::chrono::steady_clock::now() - start_time);
      }
      else {
         return prev_running_time;
      }
   }

   bool reset() {
      if (running) {
         return false;
      }
      else {
         prev_running_time = Resolution::zero(); //reset accumulated time total.
         return true;
      }
   }

   bool isRunning() const {
      return running;
   }

private:
   std::chrono::time_point<std::chrono::steady_clock> start_time{};
   Resolution prev_running_time{};

   bool running{ false };

};

// FREE FUNCTION
inline std::ostream& operator<< (std::ostream& ostr, const Stopwatch& stopwatch) {
   ostr << stopwatch.elapsed().count();
   if (stopwatch.isRunning()) {
      // ostr << " Running: Yes";
   }
   else {
      // ostr << " Running: No";
   }
   return ostr;
}
