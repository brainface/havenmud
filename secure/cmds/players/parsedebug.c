#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object who;
  if (!adminp(this_player())) who = this_player();
  if (adminp(this_player()) && args) {
    who = find_player(args);
    }
  if (!who) return "Unleash that on who?";
  
  if (!adminp(this_player()) && !this_player()->GetTestChar()) {
    return "You don't want to do that.  Really.";
  }
  if (!who) {
    return "No such target.";
    }
  if (who->GetProperty("parse debug")) {
    who->RemoveProperty("parse debug");
    debug("Parse debugging disabled for " + capitalize(who->GetKeyName()));
    return "Compliance!";
  }
  who->SetProperty("parse debug", 1);
  debug("Parse debugging enabled for " + capitalize(who->GetKeyName()));
  return "Compliance!";
}

string GetHelp(string s) {
  return 
    "Syntax:     parsedebug <who>\n\n\n"
    "Enables and disables parse debugging for a target.";
}
    
