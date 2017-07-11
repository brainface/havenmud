#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  object who = this_player();

  if (who->GetKeyName() != "fortunado") {
    return "You can't do that.";
  }


  who->eventMove("/domains/staff/room/start");
  return 1;
}

string GetHelp(string bleh) {
  return 
  "Syntax:  helpme\n"
  "Saves Fortunado when he is lost at sea.";
}
