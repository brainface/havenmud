#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object target;
  string who, what;

   if (!archp(this_player())) return 0;
  if (!args) {
      return "Send whom what?";
      }
  if (!(sscanf(args,"%s %s",who,what) == 2) ) {
       return "Send whom what?";
     }
  if (!who) {
       return "Send whom what?";
      }
  if (!what) {
       return "Send whom what?";
       }
   if (!(target = find_living(who) ) ) {
        return "No such player exists.";
        }
     else {
      message("broadcast",
   "%^BOLD%^RED%^"+this_player()->GetCapName()+" sends you: "+
    "%^RESET%^"+ what,
       target);
       message("my_action",
        "%^BOLD%^RED%^You send "+capitalize(who)+": %^RESET%^"+what,
           this_player() );
           return 1;
        }
   }
