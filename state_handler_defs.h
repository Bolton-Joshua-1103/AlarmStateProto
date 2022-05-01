#pragma once
#include <string>

enum class state_enum { disarmed = 0, pending_armed, armed, pending_alarm, alarm }; // [0,4]
inline std::string to_string(const state_enum& enum_state) {
   switch (enum_state)
   {
   case state_enum::disarmed: return "disarmed";
   case state_enum::pending_armed: return "pending_armed";
   case state_enum::armed: return "armed";
   case state_enum::pending_alarm: return "pending_alarm";
   case state_enum::alarm: return "alarm";

   default: return "unknown";
   }
}
