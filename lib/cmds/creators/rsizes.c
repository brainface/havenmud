#include <lib.h>
#include <daemons.h>
#include <size.h>
inherit LIB_DAEMON;

static void create() {
  ::create();
}

mixed cmd(string args) {
  string *races = ({ });
  string tmp;
  string spr;
  races = RACES_D->GetRaces();
  if (args) {
     if (!RACES_D->GetValidRace(args)) return "No such race.";
     races = ({ args });
    }
  races = sort_array(races, 1);
  foreach(string race in races) {
    switch(RACES_D->GetRaceSize(race)) {
      case SIZE_TINY:
         tmp =  "SIZE_TINY";
         break;
      case SIZE_VERY_SMALL:
         tmp = "SIZE_VERY_SMALL";
         break;
      case SIZE_SMALL:
         tmp = "SIZE_SMALL";
         break;
      case SIZE_MEDIUM:
         tmp = "SIZE_MEDIUM";
         break;
      case SIZE_LARGE:
         tmp = "SIZE_LARGE";
         break;
      case SIZE_VERY_LARGE:
         tmp = "SIZE_VERY_LARGE";
         break;
      case SIZE_HUGE:
         tmp = "SIZE_HUGE";
         break;
      case SIZE_GIANT:
         tmp = "SIZE_GIANT";
         break;
     }
      spr = sprintf("%:-15s %:-18s", race, tmp);
      this_player()->eventPrint(spr);
    }

  return 1;
}

string GetHelp(string useless) {
    return "Syntax:    <rsizes>"
           "Syntax:     rsizes <race>\n\n\n"
            "When used with an arg, displays only that race.\n"
            "Displays a list of all races with their size.";
}
