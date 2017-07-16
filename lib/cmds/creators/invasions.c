/*  A command to display invasions */
#include <daemons.h>
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string useless) {
  object who = this_player();
  if (!sizeof(INVASION_D->GetInvasions())) { return "No invasions currently."; }
  foreach(object invasion in INVASION_D->GetInvasions()) {
    if(!invasion) continue;
    who->eventPrint(identify(invasion));
      foreach(object invader in invasion->GetInvaderObjects()) {
  if (invader->GetCurrentEnemy() && invader->GetInCombat()) {
        message("system",
  capitalize(invader->GetKeyName()) + " (" + invader->GetLevel() + ") is at " + 
    short_file(base_name(environment(invader))) + " fighting " +
     capitalize(invader->GetCurrentEnemy()->GetKeyName()),
      who );
     }
    else {
      who->eventPrint(
   capitalize(
    invader->GetKeyName()) + " (" + invader->GetLevel() + ") is at " + 
    short_file(base_name(environment(invader))) + " and is unengaged.");
      }
 }
     who->eventPrint("-----");
      }
  return 1;
  }

string GetHelp(string useless) {
   return "Syntax:  invasions \n\n"
          "Shows all current invasions and the status of invaders.";
   }
