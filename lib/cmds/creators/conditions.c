/* Command to display conditions on a target
 * 10 June 2017 ~ Duuk
 */
#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object *who = ({ });
  
  if (!args) { who = players(); }
  
  if (args) {
    if (find_living(args)) who += ({ find_living(args) });
    else { this_player()->eventPrint("Cannot find " + args + ".");	return 1; }
  }
  
  foreach(object mahksucks in who) {
  	mahksucks->eventDisplayConditions(mahksucks, this_player());
  }
  return 1;
}

string GetHelp(string x) {
	return  "Syntax:      <conditions>\n"
	        "             <conditions> <playername>\n"
	        "\n\n"
	        "Displays either all player-active conditions, or those of a specific player.";
}