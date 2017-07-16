/*  Function to tail log players deaths */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string args) {
  if (!tail("/log/players/deaths")) 
    message("system", "No one has been killed recently.", this_player());
  return 1;
  }
string GetHelp(string x) {
  return ("Checks to see who has died recently.");
  }
