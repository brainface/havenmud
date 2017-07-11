// Amelia
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int sort(object alpha, object beta);

mixed cmd(string args) {

// Filters the users for just players
   object *people = filter(users(), (: playerp :));
   people = people - filter(people, (: base_name($1) == LIB_CONNECT :));
   people = sort_array(people, (: sort :));
// Tells you what the column is
   message("info", "%^BLUE%^BOLD%^" + 
      sprintf("%-12s %-10s %-10s %-12s %-10s %-6s",
      "Name:",
      "Race:",
      "Religion:",
      "Town:",
      "Body Temp:",
      "Level:%^RESET%^",this_player()),this_player());
// Puts the info in each column
   foreach(object who in people) {
      message("info",
      sprintf("%-12s %-10s %-10s %-12s %-12s %-3d %-8s",
      who->GetCapName(),
      who->GetRace(),
      who->GetReligion(),
      who->GetTown(),
      WEATHER_D->GetTemperatureString(who->GetWarmth()),
      who->GetLevel(),
       (who->GetClass() ? who->GetClass() : ""),
       this_player()), this_player());
   }
   return 1;
}

string GetHelp(string foo) {
    return "Syntax: <summ>\n\n"
           "Lists all of the players on the mud, including their "
           "race, religion, town, class, and level.";
}

int sort(object alpha, object beta) {
  int x = beta->GetLevel() - alpha->GetLevel();
  if (x) return x;
  return strcmp(alpha->GetCapName(), beta->GetCapName());
}
