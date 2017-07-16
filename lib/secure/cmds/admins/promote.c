/* Command to promote someone from Angel to full Immortal.
 * Duuktsaryth@Haven
 * 16 Sept 1997
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object who = this_player(), target;
  
  if (!assistp(who)) {
     return "Only Secure+ may promote Angels.";
    }
  if (who->GetForced()) {
     return "You cannot be forced to promote someone.";
     }
  if (!args) {
      return "Promote whom?";
     }
   if (!(target = find_player(args))) {
     return "Unable to find anyone like that.";
     }
  if (!angelp(target)) {
     return "That person is not an Angel.";
    }
if ( (!archp(who)) &&
        !(capitalize(who->GetKeyName()) == target->GetSponsor()) ) {
    return "You are not an Arch, and did not sponsor this person.";
    }
  CHAT_D->eventSendChannel("Promotion", "imm", 
        capitalize(this_player()->GetKeyName()) + " has promoted " +
        capitalize(target->GetKeyName()) + ".");
  unguarded( (: log_file, "secure/promote", 
                capitalize(previous_object()->GetKeyName())+" promoted "+
                capitalize(args)+" on "+ctime(time())+".\n" :) );
  target->SetAngel(0);
  target->SetShort("$N the Immortal");
  target->AddChannel( ({ "ooc", "prayer" }) );
  return 1;
  }

string GetHelp(string foo) {
  return (
     "Syntax:  promote ANGEL \n\n"
     "Allows a Secure+ immortal to promote "
     "the Angel to full Immortal status."
    );
  }
