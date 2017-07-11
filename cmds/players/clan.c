
#include <lib.h>
#include <daemons.h>
#include "include/clan.h"

inherit LIB_DAEMON;


mixed cmd(string args) {
	string what, who;
	object me = this_player();
	if (!args) {
		me->eventPrint("See \"help clan\" for syntax.");
		return 1;
	}
	if (!me->GetClan()) {
		me->eventPrint("Funny.  You're not even IN a clan!");
		return 1;
	}
	
	if (sscanf(args, "%s %s", what, who) != 2) {
		me->eventPrint("See \"help clan\" for syntax.");
		return 1;
	}
	if (CLAN_D->CheckOfficer(me->GetKeyName(), me->GetClan()) == 0) {
		me->eventPrint("You must be an officer.");
		return 1;
	}
	CHAT_D->eventSendChannel("CLAN_CMD", "reports", 
	  capitalize(me->GetKeyName()) + " issued clan command: " + args);
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
		  me->eventPrint("See \"help clan\" for syntax.");
		  break;
		}
		return 1;
}
	
		
int eventPromote(string who) {
	object lead = this_player();
	CLAN_D->AddOfficer(who, lead->GetClan());
	CHAT_D->eventSendChannel("Promotion", lead->GetClan(), 
	  capitalize(lead->GetKeyName()) + " just promoted " + capitalize(who) + 
	  " to Clan Officer.");
	return 1;
}

int eventDemote(string who) {
	object lead = this_player();
	CLAN_D->RemoveOfficer(who, lead->GetClan());
	CHAT_D->eventSendChannel("Demotion", lead->GetClan(), 
	  capitalize(lead->GetKeyName()) + " just demoted " + capitalize(who) + 
	  " from Clan Officer.");
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
  
  if(initiate->GetClan()) {
    this_player()->eventPrint("You may only initiate people without clan "
      + "affiliation.\n");
      return 1;
    }
    
  initiate->SetClan((string)this_player()->GetClan());
  CLAN_D->AddMember(str, initiate->GetClan());
  eventJoin(initiate);
  return 1;
}

void eventJoin(object ob) {
  ob->eventPrint("%^YELLOW%^You are now a member of the "
    + ((string)ob->GetClan()) + ".%^RESET%^");
  environment(ob)->eventPrint("%^YELLOW%^" +(string)ob->GetName()
    + " is now a member of the "
    + ((string)ob->GetClan()) + ".%^RESET%^", ob);
  CLAN_D->Logon(ob);
}

int eventRetire(string str) {
  object retiree;
  
  if(!str) return notify_fail("Expel whom?\n");
  CLAN_D->RemoveMember(this_player()->GetClan(), str);
  if (retiree = find_living(str)) {
  	CLAN_D->Logon(retiree);
  }
  
  return 1;
}

string GetHelp(string useless) {
	useless = "Syntax:   clan initiate <player> \n"
	          "          clan promote <player> \n"
	          "          clan demote <player> \n"
	          "          clan expel <player> \n\n"
	          "Use of this command, by a valid clan officer, allows new "
	          "members to join and members to be expelled from the clan. "
	          "It also allows officers to promote and demote other officers. "
	          "New members must be online at the time, others do not.";
 return useless;
}
