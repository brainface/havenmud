/* Command to sponsor an Angel.
 * Duuktsaryth@Haven
 * 15 Sept 1997
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object target, who;
   who = this_player();
  if (!spiritp(who)) {
    return "Only Spirits may sponsor Angels.";
    }
  if (who->GetForced()) {
     return "You cannot be forced to sponsor someone.";
    }
  if (!args) {
     return "Sponsor whom?";
   }
  if (!(target = find_player(args))) {
     return "Unable to find such a person.";
    }
  if (!angelp(target)) {
       return "You cannot sponsor someone that is not an Angel.";
      }
  if (target->GetSponsor() != "None") {
      return "That person is already sponsored!";
     }
   target->SetSponsor(capitalize(who->GetKeyName()));
   who->AddSponsoree(capitalize(target->GetKeyName()));
   target->SetShort("$N the Fledgling Immortal");
  CHAT_D->eventSendChannel("Announce", "imm", 
                 capitalize(who->GetKeyName()) + " has sponsored " +
              capitalize(target->GetKeyName()) + ".");
  unguarded( (: log_file, "secure/sponsor", 
                capitalize(previous_object()->GetKeyName())+" sponsored "+
                capitalize(args)+" on "+ctime(time())+".\n" :) );
  return 1;
 }

string GetHelp(string foo) {
  return (
    "Syntax:  sponsor APPRENTICE \n\n"
    "Allows a Spirit+ to sponsor an Angel.  By sponsoring, the Sponsor "
    "agrees to teach the Angel.  No Angel can become a full "
    "Builder without being sponsored."
    );
  }
