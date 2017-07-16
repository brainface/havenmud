#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int CanSet(object who) {
  object env = environment(who);
  
  if (env->is_estate() != 1) {
    who->eventPrint("This is not an estate room.");
    return 0;
   }
  if (env->GetOwner() != capitalize(who->GetKeyName())) {
    who->eventPrint("You are not the owner here.");
    return 0;
  }
  return 1;
}

mixed cmd(string args) {
  string thing, what;
  object who = this_player();
  object env = environment(who);
  
  if (!args) { return "eset THING to WHAT <see 'help estates'>"; }
  if (sscanf(args, "%s to %s", thing, what) != 2) {
    who->eventPrint("You must eset THING to WHAT.");
    who->eventPrint("See <help estates> to see what options you have.");
    return 1;
  }
  if (!CanSet(who)) { return 1; }
  
  switch (thing) {
    case "description":
      env->SetEstateLong(what);
      who->eventForce("look");
      CHAT_D->eventSendChannel("ESTATE", "reports", who->GetCapName() + " set description to " + what);
      write_file("/log/players/estates", who->GetCapName() + " set long to " + what + " in " + short_file(base_name(env)) + "\n");
      break;
    case "short":
      env->SetEstateShort(what);
      who->eventForce("look");
      CHAT_D->eventSendChannel("ESTATE", "reports", who->GetCapName() + " set short to " + what);
      write_file("/log/players/estates", who->GetCapName() + " set short to " + what + " in " + short_file(base_name(env)) + "\n");
      break;
    default:
      who->eventPrint("eset description to WHAT or eset short to WHAT?");
      break;
  }
  return 1;
}

string GetHelp(string u) {
  return "Syntax:                eset THING to WHAT\n\n"
         "Sets the description or short of an estate room that you own.";
}
