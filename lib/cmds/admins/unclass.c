#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object toast;

  if (!archp(this_player())) {
     return 0;
    }

  if (!args) {
    return "Set who's class to null?";
   }
  if (!(toast = find_living(args))) {
    return "Unable to find target.";
    }

   toast->RemoveClass();
   foreach(string title in toast->GetTitles()) {
   	toast->RemoveTitle(title);
    }
   this_player()->eventPrint("Unclassed.");
   toast->AddDevelopmentPoints(160);
   return 1;
  }

string GetHelp(string blah) {
    return "Syntax: <unclass [player]>\n\n"
           "This command can be used to remove a player's "
           "class. In doing so, it will remove all of their "
           "skills, spells and titles.";
}
