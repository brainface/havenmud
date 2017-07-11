#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  string *missions;
  object who = this_player();
  mapping m = ([]);
  missions = MISSION_D->LoadMissions();
  foreach(string miss in missions) {
    object tmp = load_object(miss);
    m += ([ tmp->GetMissionName() : miss ]);
    }
  map_delete(m, "Quest Template");
  who->eventPrint(
    sprintf("%-:20.20s  %-20s %-30s %-7s", "Name", "Region", "Reward", "Levels")
    );
  foreach(string mission in sort_array(keys(m), 1)) {
    object tmp = load_object(m[mission]);
    who->eventPrint(
      sprintf("%-:20.20s %-20s %-30s %-3d ~ %-3d", tmp->GetMissionName(), tmp->GetTown(), tmp->GetReward(), tmp->GetMinimumLevel(), tmp->GetMaximumLevel())
    );
  }
  return 1;
}

string GetHelp(string u) {
  return "Syntax   <questlist>\n\n"
         "Displays a list of available quests.";
}         
