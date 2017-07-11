/* Retire Command */
#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
   object who;
   who = this_player();
   if(who->GetRetired() == 0) {
        who->SetRetired(1);
CHAT_D->eventSendChannel("RETIRE", "reports", capitalize(who->GetKeyName()) + " has retired.");
        return "You have been retired.";
      }
   if(who->GetRetired() == 1) {
        who->SetRetired(0);
CHAT_D->eventSendChannel("RETIRE", "reports", capitalize(who->GetKeyName()) + " has unretired.");
        return "You have been unretired.";
      }
}

string GetHelp(string blah) {
    return "Syntax: <retire>\n\n"
           "If used on a retired person they will unretire, if used on "
           "active person it will retire them.";
}

