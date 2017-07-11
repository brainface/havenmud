#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  string *races;

  if (!args) {
    return "List player or npc races?";
    }

  if (args == "npc") {
    races = RACES_D->GetRaces();
    races = sort_array(races, 1);
  message("system",
      "The following are valid NPC races: \n"
      + conjunction(races),
    this_player() );
   return 1;
    }
  if (args == "player") {
    races = RACES_D->GetRaces(1);
    races = sort_array(races, 1);
    message("system",
     "Valid player races include: \n"
     + conjunction(races),
     this_player() );
    return 1;
   }
   return "Invalid argument.  \"races player\" or \"races npc\"";
  }

string GetHelp() {
  return ("Syntax : <racelist [player|npc] \n\n"
          "Returns all valid player|npc races that are currently \n"
          "in play.  This command is useful, really.");
  }
