//      /bin/adm/_broadcast.c
//      from the Dead Souls mudlib
//      like shout, except that it overrides ALL blocking
//      created by Descartes of Borg 930823

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
  string COL = "%^MAGENTA%^";

  if(!archp(previous_object())) return 0;
 
  
  message("broadcast",
      capitalize(this_player()->GetKeyName()) + " " + COL + "<SYSTEM>%^RESET%^ " +
      str, users() );
  return 1;
}

string GetHelp(string blah) {
    return "Syntax: <broadcast [message]>\n\n"
           "Sends out the given message as <SYSTEM> [message] and is immune "
           "to all forms of blocking. This command is intend to allow "
           "immortals to notify players of important information and should "
           "not be used for shout wars or other forms of immortal "
           "entertainment.\n\n"
           "See also: echo, echomud, lines, ooc";
}
