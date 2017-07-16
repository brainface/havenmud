
/*   The command verb. Created by Portia@Haven
     18 May, 1999
 */

#include <lib.h>
inherit LIB_VERB;

static void create() {
  verb::create();
  SetVerb("command");
  SetRules("LIV to STR");
  SetHelp(
       "Syntax : command LIV to STRING"
       "This allows a player to command a living object.");
}

mixed can_command_liv_to_str(object pet, string command) {
  if (this_player()->GetSleeping() )
    return "You are asleep!";
    return 1;
}

mixed do_command_liv_to_str(object pet, string command) {
  this_player()->eventPrint("You command " + capitalize(pet->GetKeyName()) + " to " + command + ".");
  pet->eventCommand(this_player(), command);
  return 1;
}
