#include <lib.h>
#include <std.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object *players = users();
  string *names = ({ });
  
  players = filter(players, (: playerp :) );
  names = players->GetKeyName();
  
  names = sort_array(names, 1);
  this_player()->eventPrint(sprintf("%-15s %-30s", "Player", "Mission"));
  foreach(string name in names) {
    string tmp  = find_player(name)->GetProperty("mission");
    object miss;
    if (tmp) miss = load_object(tmp);
    if (miss) this_player()->eventPrint(sprintf("%-15s %-30s", capitalize(name), miss->GetMissionName()));
      else this_player()->eventPrint(sprintf("%-15s %-30s", capitalize(name), "No Mission"));
    }
  return 1;
}

string GetHelp(string x) {
  return "Syntax:    missions\n\n"
         "Displays all active missions for current players.";
}
         