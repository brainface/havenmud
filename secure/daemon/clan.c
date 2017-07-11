/* Clan Daemon */
#include <lib.h>
#include <save.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_PERSIST;

private mapping Clans;
private mapping Leaders;
private mapping Officers;

void SortClans();

static void create() {
  ::create();
  AddSave( ({ "Clans", "Leaders", "Officers" }) );
  SetNoClean(1);
  Clans = ([ ]);
  Leaders = ([ ]);
  Officers = ([ ]);
  restore_object(SAVE_CLAN);
  SortClans();
  save_object(SAVE_CLAN);
}

string *GetClans() {
	return keys(Clans);
}

string *GetMembers(string clan) {
	return Clans[clan];
}

string GetLeader(string clan) {
	return Leaders[clan];
}

string *AddMember(string who, string clan) {
	Clans[clan] = distinct_array(Clans[clan] + ({ lower_case(who) }));
	if (Leaders[clan] == "") Leaders[clan] = who;
	unguarded( (: save_object, SAVE_CLAN:) );
	return Clans[clan];
}

string *RemoveMember(string who, string clan) {
	Clans[clan] -= ({ lower_case(who) });
	unguarded( (: save_object, SAVE_CLAN:) );
	return Clans[clan];
}

string *AddClan(string clan) {
	if (Clans[clan]) return 0; // Don't want to mess up existing clans.
	Clans[clan] = ({ });
	Leaders[clan] = "";
	Officers[clan] = ({ });
	unguarded( (: save_object, SAVE_CLAN:) );
	return keys(Clans);
}

string *RemoveClan(string clan) {
	if (sizeof(Clans[clan])) {
		error("*Tried to remove a clan with valid players: " +
		      conjunction(Clans[clan], "and") + " are still in this clan!");
		return 0;
	}
	map_delete(Clans, clan);
	map_delete(Leaders, clan);
	map_delete(Officers, clan);
	unguarded( (: save_object, SAVE_CLAN:) );
	return keys(Clans);
}

string SetLeader(string who, string clan) {
	if (!Clans[clan]) return 0;
	Leaders[clan] = lower_case(who);
	unguarded( (: save_object, SAVE_CLAN:) );
	return Leaders[clan];
}

mapping GetLeaders() {
	return Leaders;
}

int CheckMember(object who, string clan) {
	if (!Clans[clan]) return 0;
	if (member_array(who->GetKeyName(), Clans[clan]) != -1) return 1;
	return 0;
}

string *GetOfficers(string clan) {
	return Officers[clan];
}

string *AddOfficer(string who, string clan) {
	Officers[clan] = distinct_array(Officers[clan] + ({ who }) );
	save_object(SAVE_CLAN);
	return Officers[clan];
}

string *RemoveOfficer(string who, string clan) {
	Officers[clan] = distinct_array(Officers[clan] - ({ who }) );
	save_object(SAVE_CLAN);
	return Officers[clan];
}

int CheckOfficer(string who, string clan) {
	if (Leaders[clan] == who) return 1;
	if (member_array(who, Officers[clan]) != -1) return 1;
	return 0;
}

	
void Logon(object who) {
	if (!who->GetClan()) return;
  if (!CheckMember(who, who->GetClan())) {
  	who->SetClan(0);
  	who->eventPrint("You are no longer a member of a clan.");
  	return;
  }
  who->eventPrint("Welcome back to the " + (who->GetClan()) + "!");
  who->AddChannel(who->GetClan());
  CHAT_D->eventSendChannel("Welcome", who->GetClan(), 
    who->GetCapName() + " has rejoined this reality.");
  return;
}

void SortClans() {
	foreach(string clan in keys(Clans)) {
		Clans[clan] = filter(Clans[clan], (: user_exists :) );
		if (!sizeof(Clans[clan])) {
			 RemoveClan(clan);
		   CHAT_D->eventSendChannel("CLAN_D", "reports", 
		      "Clan (" + clan + ") Deleted -- Lack of Members.");
	   }
	 }
}

		
