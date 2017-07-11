/*  /cmds/players/idle
 *  Simple command which displays named player's idle time
 *  Recreated by Blitz@Dead Souls 960108
 *  Updated for Haven Power Idlers by Duuk
 *  23 July 2001
 *  Sort of rewritten (just a little bit) by Zedd 09/13/2001 04:50A
  * Made so WhoInvis blocks it - Laoise, 2004
 */
#include <daemons.h>
 
mixed cmd(string args) {
  int* x;
  int y;
  object who;
  string* str = ({ });

  if (!sizeof(args)) return "Syntax: idle <user name>";
  
  args = convert_name(args);
  who = find_player(args);

  if (!who || who->GetInvis() > rank(this_player()) || who->GetWhoInvis())
    return "Unable to locate anyone by that name.";
  if (!interactive(who)) return (string)who->GetName() + " is link dead.";
  if (!creatorp(this_player())) {
   CHAT_D->eventSendChannel("Idle", "spam", this_player()->GetKeyName() + " checked to see how long " + who->GetKeyName() + " was idle.");
   who->eventPrint(capitalize(this_player()->GetKeyName()) + " checked to see how long you were idle.");
  }
  if (args == "duuk") return "Duuk might be idle.  But he might not be.  Muahahahahaha.";
  y = query_idle(who);
  x = time_units(y);
  if (y < 30) return (who->GetName() + " is not idle.");
  if (x[0]) str += ({ consolidate(x[0], "one week")   });
  if (x[1]) str += ({ consolidate(x[1], "one day")    });
  if (x[2]) str += ({ consolidate(x[2], "one hour")   });
  if (x[3]) str += ({ consolidate(x[3], "one minute") });
  if (x[4]) str += ({ consolidate(x[4], "one second") });
  return (who->GetName() + " has been idle for " + conjunction(str) + ".");
}
 
string GetHelp(string str) {
    return "Syntax: idle <user name>\n\n"
           "Displays named user's idle time.  A user's \"idle time\" is "
           "the amount of time since the named user last sent input "
           "to the MUD.";
}
