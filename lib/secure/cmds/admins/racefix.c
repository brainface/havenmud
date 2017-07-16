// mahkefel 2014
//   second time fixing races late at night
//   is now a command to take 5 seconds.
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  RACES_D->RemakeRaces();
}

string GetHelp(string blah) {
    return "Syntax: <racefix [player]>\n\n"
      "This command fixes races. It does not induce bigotry nor end it.";
}

