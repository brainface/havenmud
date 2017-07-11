
#include <lib.h>
#include <daemons.h>
#include "include/guild.h"

inherit LIB_DAEMON;


mixed cmd(string args) {
	string what, who;
	object me = this_player();
	if (!args) {
		me->eventPrint("See \"help guild\" for syntax.");
		return 1;
	}
	if (!me->GetGuild()) {
		me->eventPrint("Funny.  You're not even IN a guild!");
		return 1;
	}
	
	if (sscanf(args, "%s %s", what, who) != 2) {
		me->eventPrint("See \"help guild\" for syntax.");
		return 1;
	}
	if (GUILD_D->CheckOfficer(me->GetKeyName(), me->GetGuild()) == 0) {
		me->eventPrint("You must be an officer.");
		return 1;
	}
	CHAT_D->eventSendChannel("GUILD_CMD", "reports", 
	  capitalize(me->GetKeyName()) + " issued guild command: " + args);
	switch(what) {
		case "initiate":
		  eventInitiate(who);
		  break;
		case "expel":
		  eventRetire(who);
		  break;
		case "promote":
		  eventPromote(who);
		  break;
		case "demote":
		  eventDemote(who);
		  break;
		default:
		  me->eventPrint("See \"help guild\" for syntax.");
		  break;
		}
		return 1;
}
	
		
int eventPromote(string who) {
	object lead = this_player();
	GUILD_D->AddOfficer(who, lead->GetGuild());
	CHAT_D->eventSendChannel("Promotion", lead->GetGuild(), 
	  capitalize(lead->GetKeyName()) + " just promoted " + capitalize(who) + 
	  " to Guild Officer.");
	return 1;
}

int eventDemote(string who) {
	object lead = this_player();
	GUILD_D->RemoveOfficer(who, lead->GetGuild());
	CHAT_D->eventSendChannel("Demotion", lead->GetGuild(), 
	  capitalize(lead->GetKeyName()) + " just demoted " + capitalize(who) + 
	  " from Guild Officer.");
	return 1;
}

	    

int eventInitiate(string str) {
  object initiate;
  
  if(!str) return notify_fail("Initiate whom?\n");
  initiate = present(lower_case(str), environment(this_player()));
  if(!initiate || !living(initiate)) {
    this_player()->eventPrint("No one of that nature here.\n");
    return 1;
  }
  
  if(initiate->GetGuild()) {
    this_player()->eventPrint("You may only initiate people without guild "
      + "affiliation.\n");
      return 1;
    }
    
  initiate->SetGuild((string)this_player()->GetGuild());
  GUILD_D->AddMember(str, initiate->GetGuild());
  eventJoin(initiate);
  return 1;
}

void eventJoin(object ob) {
  ob->eventPrint("%^YELLOW%^You are now a member of the "
    + ((string)ob->GetGuild()) + ".%^RESET%^");
  environment(ob)->eventPrint("%^YELLOW%^" +(string)ob->GetName()
    + " is now a member of the "
    + ((string)ob->GetGuild()) + ".%^RESET%^", ob);
  GUILD_D->Logon(ob);
}

int eventRetire(string str) {
  object retiree;
  
  if(!str) return notify_fail("Expel whom?\n");
  GUILD_D->RemoveMember(this_player()->GetGuild(), str);
  if (retiree = find_living(str)) {
  	GUILD_D->Logon(retiree);
  }
  
  return 1;
}

string GetHelp(string useless) {
	useless = "Syntax:   guild initiate <player> \n"
	          "          guild promote <player> \n"
	          "          guild demote <player> \n"
	          "          guild expel <player> \n\n"
	          "Use of this command, by a valid guild officer, allows new "
	          "members to join and members to be expelled from the guild. "
	          "It also allows officers to promote and demote other officers. "
	          "New members must be online at the time, others do not.";
 return useless;
}
