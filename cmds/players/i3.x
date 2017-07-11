#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

string GetHelp(string str) {
  return "This command toggles your i3 setting. Be warned that " +
      "intermud conversations can be volatile and crude. " +
      "To turn intergossip off, type 'intergossip' as you would to "+
      "block ooc.";
}

mixed cmd(string args) {
  object who = this_player();

  if (who->GetProperty("i3ban")) {
    who->eventPrint("You are not allowed.  Sorry.");
  return 1;
  }
  

  if (!legendp(who)) {
  who->eventPrint("You cannot do that until Legendary status. (Level 50)");
    return 1;
  }
  who->SetPermanentProperty("i3_enable", 1);
  CHAT_D->eventSendChannel("i3 command", "reports", 
      capitalize(who->GetKeyName()) + " has turned intergossip on.");
  who->AddChannel("intergossip");
  who->AddChannel("isport");
  who->AddChannel("hl");
  who->eventPrint("Turned intergossip on.  Be aware this channel "
                  "is often crude and connects several muds. "
                  "Your i3 status may be revoked if abused.");
  return 1;
}
