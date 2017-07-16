/*  Checks for outbreaks of plague */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd() {
  object players = filter(livings(), (: noncreatorp :) );
  object *germs = ({ });
  object *infected = ({ });
  
  foreach(object p in players) {
    if(sizeof(germs = filter(all_inventory(p), (: $1->GetProperty("germ") :) )))
      infected += ({ p });
    }
  if (!sizeof(infected)) return "No Infected People";
  this_player()->eventPrint(sprintf("%-22s %-22s %-4s %s", "Sick Person", "Disease", "Life", "Location"));
  foreach(object sicko in infected) {
    germs = filter(all_inventory(sicko), (: $1->GetProperty("germ") :) );
    foreach(object g in germs) {
      this_player()->eventPrint(
        sprintf("%-22s %-22s %-4d %s", capitalize(sicko->GetKeyName()), g->GetKeyName(), g->GetLifeSpan(), short_file(base_name(environment(sicko)))) );
      }
  }
 return 1;
 }

string GetHelp() {
  return ("Syntax: <outbreaks> \n\n"
         "Shows who has what sickness.");
  }
