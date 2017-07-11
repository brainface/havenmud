#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string useless) {
  object who = this_player();

  if (!duukp(who)) {
    return "Only Duuk can trigger a purge.";
    }
  PURGE_D->eventClean();
  PURGE_D->eventDestruct();
  return "Purged!";
}

string GetHelp(string s) {
  return "Syntax:     <purge>\n\n\n" 
         "Runs the purge daemon.  fduh.";
}
