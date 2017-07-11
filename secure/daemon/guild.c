/* Guild Daemon */
#include <lib.h>
#include <save.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_PERSIST;

private mapping Guilds;
private mapping Leaders;
private mapping Officers;

void SortGuilds();

static void create() {
  ::create();
  AddSave( ({ "Guilds", "Leaders", "Officers" }) );
  SetNoClean(1);
  Guilds = ([ ]);
  Leaders = ([ ]);
  Officers = ([ ]);
  restore_object(SAVE_GUILD);
  SortGuilds();
  save_object(SAVE_GUILD);
}

string *GetGuilds() {
	return keys(Guilds);
}

string *GetMembers(string guild) {
	return Guilds[guild];
}

string GetLeader(string guild) {
	return Leaders[guild];
}

string *AddMember(string who, string guild) {
	Guilds[guild] = distinct_array(Guilds[guild] + ({ lower_case(who) }));
	if (Leaders[guild] == "") Leaders[guild] = who;
	unguarded( (: save_object, SAVE_GUILD:) );
	return Guilds[guild];
}

string *RemoveMember(string who, string guild) {
	Guilds[guild] -= ({ lower_case(who) });
	unguarded( (: save_object, SAVE_GUILD:) );
	return Guilds[guild];
}

string *AddGuild(string guild) {
	if (Guilds[guild]) return 0; // Don't want to mess up existing guilds.
	Guilds[guild] = ({ });
	Leaders[guild] = "";
	Officers[guild] = ({ });
	unguarded( (: save_object, SAVE_GUILD:) );
	return keys(Guilds);
}

string *RemoveGuild(string guild) {
	if (sizeof(Guilds[guild])) {
		error("*Tried to remove a guild with valid players: " +
		      conjunction(Guilds[guild], "and") + " are still in this guild!");
		return 0;
	}
	map_delete(Guilds, guild);
	map_delete(Leaders, guild);
	map_delete(Officers, guild);
	unguarded( (: save_object, SAVE_GUILD:) );
	return keys(Guilds);
}

string SetLeader(string who, string guild) {
	if (!Guilds[guild]) return 0;
	Leaders[guild] = lower_case(who);
	unguarded( (: save_object, SAVE_GUILD:) );
	return Leaders[guild];
}

mapping GetLeaders() {
	return Leaders;
}

int CheckMember(object who, string guild) {
	if (!Guilds[guild]) return 0;
	if (member_array(who->GetKeyName(), Guilds[guild]) != -1) return 1;
	return 0;
}

string *GetOfficers(string guild) {
	return Officers[guild];
}

string *AddOfficer(string who, string guild) {
	Officers[guild] = distinct_array(Officers[guild] + ({ who }) );
	save_object(SAVE_GUILD);
	return Officers[guild];
}

string *RemoveOfficer(string who, string guild) {
	Officers[guild] = distinct_array(Officers[guild] - ({ who }) );
	save_object(SAVE_GUILD);
	return Officers[guild];
}

int CheckOfficer(string who, string guild) {
	if (Leaders[guild] == who) return 1;
	if (member_array(who, Officers[guild]) != -1) return 1;
	return 0;
}

	
void Logon(object who) {
	if (!who->GetGuild()) return;
  if (!CheckMember(who, who->GetGuild())) {
  	who->SetGuild(0);
  	who->eventPrint("You are no longer a member of a guild.");
  	return;
  }
  who->eventPrint("Welcome back to the " + (who->GetGuild()) + "!");
  who->AddChannel(who->GetGuild());
  CHAT_D->eventSendChannel("Welcome", who->GetGuild(), 
    who->GetCapName() + " has rejoined this reality.");
  return;
}

void SortGuilds() {
	foreach(string guild in keys(Guilds)) {
		Guilds[guild] = filter(Guilds[guild], (: user_exists :) );
		if (!sizeof(Guilds[guild])) {
			 RemoveGuild(guild);
		   CHAT_D->eventSendChannel("GUILD_D", "reports", 
		      "Guild (" + guild + ") Deleted -- Lack of Members.");
	   }
	 }
}

		
