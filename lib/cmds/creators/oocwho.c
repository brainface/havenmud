/*  Show's who's who */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string who) {
  this_player()->eventPrint(sprintf("%:-15s %:-15s %:-15s %:-15s", "IC Name",
                                 "OOC Name", "Real Name", "Email"));
  this_player()->eventPrint("%^YELLOW%^BOLD%^------------------------"
                            "------------------------------------%^RESET%^");
  foreach(object user in filter(users(), (: playerp :) ) ){
    this_player()->eventPrint(sprintf("%:-15s %:-15s %:-15s %s",
                                      capitalize(user->GetKeyName()),
                                      user->GetOOCName(),
                                      user->GetRealName(),
                                      user->GetEmail()));
  }
  return 1;
}

string GetHelp(string blah) {
  return "Syntax: <oocwho>\n\n"
         "Shows who is really who on OOC.";
}
