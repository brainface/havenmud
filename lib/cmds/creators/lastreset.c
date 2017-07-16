#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object room, who;
  who = this_player();
  
  if (!args) args = "here";
  if (args == "here") { room = environment(who); }
  if (!room) { room = find_player(args); room = environment(room); }
  if (!room) { room = load_object(args); }
  if (!room) return "Can't find a target.  Sorry, etc.";
  return short_file(base_name(room)) + " was last reset at " + room->GetLastResetTime();
}

string GetHelp(string u) {
  return "Syntax  lastreset <filename> \n"
         "        lastreset here       \n"
         "        lastreset <player>   \n\n"
         "Using this command, you can see when either a room file <filename> "
         "the current room you are in <here> or the room a player is standing "
         "in <player> was last reset.";
}
        
         
    
    
    