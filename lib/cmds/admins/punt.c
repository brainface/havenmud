#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string arg) {
  object target, who, room;
  string dir;
  string *tmp = ({ });
  string prev_room;
  who = this_player();
     
  if (!arg) {
      who->eventPrint("Punt who where?");
      return 1;
  }
  tmp = explode(arg, " ");
  if (sizeof(tmp) != 2) {
      who->eventPrint("Punt who where?");
      return 1;
  }
  arg = tmp[0];
  dir = tmp[1];
  target = present(arg, environment(who));
  
  if (!target) { 
      who->eventPrint("Punt who where?");
      return 1;
  }
  prev_room = file_name(environment(target));
  while (dir) {
    room = environment(target);
    if (!room->GetExit(dir)) {
      dir = 0;
      send_messages( ({ "fall" }), "$agent_name $agent_verb to the floor with a thump.", target, 0, room);
      break;
      }
    target->eventMoveLiving(room->GetExit(dir), "$N flies through the air to the " + dir + ".", "$N flies in.");
    if (file_name(environment(target)) == prev_room) {
    	send_messages( ({ "fall" }), "$agent_name $agent_verb to the floor with a thump.", target, 0, room);
    	break;
    }
  }
  return 1;
}

string GetHelp(string u) {
  return  "Syntax:    punt <who>  <direction> \n\n"
          "Punts someone in a direction.  They continue until they can't go anymore.";
}