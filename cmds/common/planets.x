#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  string *planets = PLANETS_D->GetPlanets();
  object who = this_player();
  mixed *tmp;
  
  planets = sort_array(planets, 1);
  who->eventPrint(sprintf("%-20s %-15s %-10s %-10s %-10s", "World", "System", "X", "Y", "Z"));
  foreach(string planet in planets) {
    tmp = PLANETS_D->GetPlanetGrid(planet);
    who->eventPrint(sprintf("%-20s %-15s %-10d %-10d %-10d", capitalize(planet), tmp[0], (int)tmp[1][0], (int)tmp[1][1], (int)tmp[1][2]));
  }
  return 1;
}

string GetHelp(string u) {
  return "Displays a list of the current planets listed in the PLANETS_D";
}