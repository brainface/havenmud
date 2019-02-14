/* mahk 2019
 * decorate the interior of a wagon or ship
 * Largely a copy of eset
 */

#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int CanDecorate(object who) {
  object wagon = environment(who);

  if (!wagon) {
    who->eventPrint("You are nowhere, and that is bad.");
    return 0;
  } 
  if (!vehiclep(wagon)) {
    who->eventPrint("You must be inside a vehicle to decorate. Yes, "
      "you must be inside a vehicle to decorate the outside it's magic.");
    return 0;
   }
  if (wagon->GetOwner() != who->GetKeyName()) {
    who->eventPrint("You don't own this and shouldn't redecorate it.");
    return 0;
  }
  return 1;
}

mixed cmd(string args) {
  string thing, what;
  object who = this_player();
  object env = environment(who);
  
  if (!args) { return "decorate WHAT to HOW <see 'help wagons'>"; }
  if (sscanf(args, "%s to %s", thing, what) != 2) {
    who->eventPrint("You must decorate interior to (some description) "
		    "or decorate exterior to (some description).");
    who->eventPrint("See <help wagons> to see what options you have.");
    return 1;
  }
  if (!CanDecorate(who)) { return 1; }
  
  switch (thing) {
    case "interior":
      env->SetBridgeDescription(what);
      who->eventForce("look");
      CHAT_D->eventSendChannel("VEHICLE", "reports", who->GetCapName() + " set description to " + what);
      // there's no vehicles logfile, so it's going to estates anyway
      write_file("/log/players/estates", who->GetCapName() + " set long to " + what + " in " + short_file(base_name(env)) + "\n");
      break;
    case "exterior":
      env->SetLong(what);
      who->eventPrint(env->GetExternalDesc(who));
      CHAT_D->eventSendChannel("VEHICLE", "reports", who->GetCapName() + " set short to " + what);
      // again, no vehicles logfile
      write_file("/log/players/estates", who->GetCapName() + " set short to " + what + " in " + short_file(base_name(env)) + "\n");
      break;
    default:
      who->eventPrint("decorate interior to WHAT or decorate exterior to WHAT?");
      break;
  }
  return 1;
}

string GetHelp(string u) {
  return "Syntax:     decorate interior to WHAT\n"
         "            decorate exterior to WHAT\n\n"
         "Sets the interior description or exterior description of a vehicle you own.\n"
         "You cannot change the name of a vehicle (the short description that appears \n"
         "when the vehicle moves or is interacted with. You must be aboard the vehicle \n"
         "to decorate it.";
}
