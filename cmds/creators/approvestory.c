#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int cmd(string target) {
  object who = this_player();
  object newbie;
    
    if (!musep(who)) {
        who->eventPrint("You are not a member of the roleplaying group.");
        return 1;
    }

  if (!target) {
    who->eventPrint("Who do you want to approve?");
    return 1;
    }
  if (!newbie = find_player(target)) {
    who->eventPrint("Unable to find anyone with that name.");
    return 1;
    }
  if (creatorp(newbie)) {
    who->eventPrint("Approve of an Immortal?  That's pointless.");
    return 1;
    }
  if (newbie->GetApprovedStory()) {
    who->eventPrint("That person has already been approved.");
    return 1;
    }
/* commented out--story approve can now be down after newbie mahkefel 2011
  if (!newbiep(newbie)) {
    who->eventPrint("I think you missed the boat on that one.");
    return 1;
    }
*/
  newbie->SetApprovedStory(1);
  newbie->eventPrint("%^BOLD%^YELLOW%^You have been approved to advance.");
  who->eventPrint("You approve of " + capitalize(newbie->GetKeyName()) + ".");
  CHAT_D->eventSendChannel("Approval", "reports", 
    capitalize(who->GetKeyName()) + " has approved of " + capitalize(target) + ".");
  return 1;
}
  
string GetHelp(string bleh) {
	return "Use this command to approve of a character story, thus allowing "
	       "a newbie to advance to mortal.";
}
  
