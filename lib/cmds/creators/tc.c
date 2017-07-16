#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

static void create() {
  ::create();
  SetNoClean(1);
}

mixed cmd(string target) {
  object who;
  object me;
  me = this_player();

  if (!target) return "Make who a test character?";
  if (angelp(me)) return "You're not allowed.";
  if (!who = find_player(target)) return "Sorry, can't find " + target;
  if (who->GetTestChar()) return "Too late.  They already are!";
  who->SetTestChar(1);
  CHAT_D->eventSendChannel("Test Character", "reports", capitalize(me->GetKeyName()) + 
                  " has flagged " + capitalize(who->GetKeyName()) + " as a Test Character.");
  write_file("/log/adm/tc",
     capitalize(me->GetKeyName()) + 
            " has flagged " + capitalize(who->GetKeyName()) + " as a Test Character. " 
            + ctime(time()) + "\n");
  return 1;
}

string GetHelp(string why) {
  return "Syntax:  tc <who>\n\n\n" 
         "Flags a character as a test character.  Keeps you from getting yelled at.";
}
