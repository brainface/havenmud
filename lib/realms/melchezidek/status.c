/*    /cmds/player/status.c
 *    from the Dead Souls LPC Library
 *    gives a player status information
 *    created by Descartes of Borg 950409
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
  int hp, maxhp, mp, maxmp, sp, maxsp;
  string s = "/", b = " ", hpx = "%^YELLOW%^hp:%^RESET%^ ", 
  mpx = " %^BLUE%^mp:%^RESET%^ ", spx = " %^GREEN%^sp:%^RESET%^ ";
  object liv;

  if (!args) {
     if (creatorp(this_player())) return this_player()->eventPrint("Get status for who?");
     return this_player()->eventDisplayStatus();
  } else {
     switch(args) {
       case "hp":
         hp    = this_player()->GetHealthPoints();
         maxhp = this_player()->GetMaxHealthPoints();
         return this_player()->eventPrint(hpx+hp+s+maxhp);
       case "mp":
         mp    = this_player()->GetMagicPoints();
         maxmp = this_player()->GetMaxMagicPoints();
         return this_player()->eventPrint(mpx+mp+s+maxmp);
       case "sp":
         sp    = this_player()->GetStaminaPoints();
         maxsp = this_player()->GetMaxStaminaPoints();
         return this_player()->eventPrint(spx+sp+s+maxsp);
       default:
         if(liv = find_living(args)) {
           hp    = liv->GetHealthPoints();
           maxhp = liv->GetMaxHealthPoints();
           mp    = liv->GetMagicPoints();
           maxmp = liv->GetMaxMagicPoints();
           sp    = liv->GetStaminaPoints();
           maxsp = to_int(liv->GetMaxStaminaPoints());
           return this_player()->eventPrint( hpx+hp+s+maxhp+mpx+mp+s+maxmp+spx+sp+s+maxsp );
        } else {
          if (creatorp(this_player())) {
            return this_player()->eventPrint("No such player.");
          } else {
            return this_player()->eventPrint("Status what? Choose hp, mp, or sp.");
          }

       }
     }
  }
}

void help() {
    message("help", "Syntax: <status>\n\n"
            "Gives you information about your current physical status.\n\n"
            "See also: money, skills, stats", this_player());
}
