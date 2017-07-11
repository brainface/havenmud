#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string target) {
  object who;
  if (!creatorp(this_player())) who = this_player();
  if (!target) target = this_player()->GetKeyName();
  if (creatorp(this_player())) {
  	who = find_player(target);
  }
  if (!who) { return "Display reputations for whom?"; }
  if (creatorp(who)) { return "Immortal Reputation:  Lazy"; }
  who->DisplayReputations(this_player());
  return 1;
}

string GetHelp(string u) {
	string m =                        "Syntax:   reputation\n";
	if (creatorp(this_player())) m += "          reputation <target>\n";
	m += "\n\nUse this command to display information about faction reputation.";
	return m;
}