#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object target;
  if (!creatorp(this_player())) { return 0; }
  if (!args) {
    return "Rifle through whose pockets?";
    }
  if (!(target = find_living(args))) {
     return "No such person.";
     }
  if (!args) {
     return "Can't find that person.";
    }
  foreach(string curr in (target->GetCurrencies())) {
   this_player()->eventPrint(curr + " : " + target->GetCurrency(curr));
  }
  return 1;
  }

string GetHelp(string blah) {
    return "Syntax: <cash [player]>\n\n"
           "Will show you the current amount of money a player "
           "has in their possession.\n\n"
           "See also: body, objects, stat, skills";
}
