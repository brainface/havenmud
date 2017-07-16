#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

string GetHelp(string u) {
  return "Use this command to set a perm property in someone. \n" +
        "Syntax:  pprop person property";
}

mixed cmd(string args) {
  string who, what;
  object target;

  sscanf(args, "%s %s", who, what);
  target = find_player(who);
  if (!target) {
    return "Set property on who dumbass?";
    }
  if (!what) {
    return "Set what property dumbass?";
    }
  target->SetPermanentProperty(what);
  return "Success";
}
