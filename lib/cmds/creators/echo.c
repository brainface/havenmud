/*  New Improved Echo cmds
 *   Duuktsaryth
 *  Added RP Notification - Dylanthalus@haven
 */
#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  object target;
  object who = this_player(); 
  string person, str;
  if (angelp(this_player())) { return 0; }
  if (!args) { return "Echo what or what to who?"; }
  sscanf(args,"to %s %s", person, str);
  if (!person) {
      target = environment(this_player());
      str = args;
     }
   else {
       target = find_living(person);
       if (target->GetInvis() > rank(this_player())) target = 0;
       }
   if (!str) {
      return "Echo what?";
      }
  if (!target) {
       return "No target or current environment.";
     }
  if (creatorp(target)) {
  message("my_action",
     "You echo \"" + str + "\" to " + target->GetShort() + ".",
      this_player() );
   return 1;
     }
  else {
  this_player()->eventPrint("You echo \"" + str + "\" to " + target->GetShort() + ".");
  message("system",str,target);
  CHAT_D->eventSendChannel("Echo Report", "reports", capitalize(who->GetCapName())+ " echoed to "+target->GetShort()+" : "+str);
  return 1;
  }
}

string GetHelp(string blah) {
    return "Syntax: <echo [message]>\n"
           "        <echo to [player] [message]>\n\n"
           "With just a message it will echo that message to your current "
           "environment. With a player as argument, it will echo the message "
           "to them.";
}
