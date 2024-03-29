#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string prayer) {
  object who = this_player();
  if (!(who->GetReligion())) {
  	 who->eventPrint("You must have a religion.");
  	 return 1;
  	}
  	
  if (who->GetReligion() == "agnostic") {
  	who->eventPrint("No one listens to the prayers of an agnostic.");
  	return 1;
  	
  }
   if(!prayer) return "Pray about what?";
  send_messages("mutter", "$agent_name $agent_verb a little prayer.", who, 0,
    environment(who) );
  CHAT_D->eventSendChannel(who->GetReligion(), "prayer",
    capitalize(who->GetKeyName()) + ": " + prayer);
  unguarded( (: log_file, "reports/prayer", capitalize(who->GetKeyName()) + " (" +
      who->GetReligion() + ") prayed: \"" + prayer + "\" at "+ctime(time()) + ".\n\n" :));
  return 1;
}

string GetHelp(string useless) {
	return "This command sends a prayer, using _exactly_ the text you "
	       "enter, to your deity. Be aware that you MUST have an active "
	       "religion (not agnostic) and MUST keep this in-character. \n"
	       "Immortals/Deities to pray to: \n"
	       "Saahagoth: Arika \n"
	       "Soirin   : Alessandra \n"
	       "Aberach  : Laoise \n"
	       "Kylin    : Duuktsaryth \n"
	       "Kuthar   : Spirits of Ancestors \n"
	       "Magildan : Zaxan, Vanyel or Dylanthalus \n"
	       "Eclat    : Amelia \n"
	       ;
	      }
	      
