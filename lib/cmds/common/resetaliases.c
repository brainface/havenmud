#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object who = this_player();
  
  who->ResetAliases();
  who->eventPrint("Aliases Reset to default!");
  CHAT_D->eventSendChannel("Alias Reset", "reports", capitalize(who->GetKeyName()) + " reset " + possessive(who) + " alias list.");
  return 1;
}

string GetHelp(string u) {
  return "Syntax:   <resetaliases>\n\n"
         "Resets aliases to the default alias list.";
}
         