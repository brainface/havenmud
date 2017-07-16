#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string who) {
  object target;
  if (!who) {
    return "Viking who?";
   }
  target = find_player(who);
  if (!target) {
    return "No such player";
    }
  if (creatorp(target)) {
    return "No.";
    }
  target->SetViking(!(target->GetViking()));
  if (target->GetViking()) {
    CHAT_D->eventSendChannel("Viking!", "reports", 
    capitalize(this_player()->GetKeyName()) + " has vikinged " + capitalize(who) );
   target->eventPrint("%^BOLD%^YELLOW%^You have been turned into a %^BLUE%^Viking!%^RESET%^");
    return who + " vikinged.";
    }
    CHAT_D->eventSendChannel("Viking!", "reports", 
    capitalize(this_player()->GetKeyName()) + " has unvikinged " + capitalize(who) );
   target->eventPrint("%^BOLD%^YELLOW%^You are no longer a %^BLUE%^Viking!%^RESET%^");
   return who + " unvikinged.";
}

string GetHelp(string blah) {
    return "Syntax: <viking [player]>\n\n"
           "This command will turn the named player in to a viking, "
           "which will make them only able to speak in viking, "
           "including on ooc, and will change their title to reflect "
           "their new status. Useful for punishing a player without "
           "needing to zap or damn them.\n\n"
           "See also: channel, damn, zap";
}
