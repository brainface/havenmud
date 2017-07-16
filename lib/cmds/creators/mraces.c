/* new mraces Duuk */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  string *races = RACES_D->GetRaces();
  return implode(sort_array(races, 1 ), ", ");
}

string GetHelp(string blah) {
  return "Syntax: <mraces>\n\n"
         "Gives a list of currently avaliable npc races.";
}
