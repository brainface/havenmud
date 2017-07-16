/*    /lib/npc.c
 *    from the Dead Souls LPC Library
 *    a npc basenpc
 *    created by Descartes of Borg 950331
 *    Version: @(#) npc.c 1.5@(#)
 *    Last modified: 96/12/15
 */

#include <lib.h>
#include <function.h>
#include <daemons.h>

inherit LIB_BASENPC;

private mapping     CommandResponses = ([ ]);
private mapping     EmoteResponses   = ([]);
private mapping     RequestResponses = ([]);
private mapping     TalkResponses    = ([]);
static private int  WanderCount      = 0;
static private int  WanderMarker     = 0;
private mixed array WanderPath       = ({});
private int         WanderRecurse    = 0;
private int         WanderSpeed      = 0;

/* ******************  /lib/npc.c data manipulation  **************** */
/**
 * This method is called to see if anything is going on requiring
 * the NPC to keep its heart beat going.
 * @return true if the heart beat should continue
 */
static int ContinueHeart() {
    if( WanderSpeed ) {
	return 1;
    }
    else {
	return basenpc::ContinueHeart();
    }
}

mixed AddCommandResponse(string str, mixed val) {
    return (CommandResponses[str] = val);
}

mixed GetCommandResponse(string str) {
    return CommandResponses[str];
}

mapping GetCommandResponses() {
    return CommandResponses;
}

int RemoveCommandResponse(string str) {
    if( !CommandResponses[str] ) {
	return 0;
    }
    map_delete(CommandResponses, str);
    return 1;
}

mapping SetCommandResponses(mapping mp) {
    return (CommandResponses = expand_keys(mp));
}

mixed AddEmoteResponse(string verb, mixed val) {
    return (EmoteResponses[verb] = val);
}

mixed GetEmoteResponse(string verb) {
    return EmoteResponses[verb];
}

mapping GetEmoteResponses() {
    return EmoteResponses;
}

int RemoveEmoteResponse(string verb) {
    if( !EmoteResponses[verb] ) {
	return 0;
    }
    map_delete(EmoteResponses, verb);
    return 1;
}

mapping SetEmoteResponses(mapping mp) {
    return (EmoteResponses = expand_keys(mp));
}

mixed AddRequestResponse(string str, mixed val) {
    return (RequestResponses[str] = val);
}

mixed GetRequestResponse(string str) {
    return RequestResponses[str];
}

mapping GetRequestResponses() {
    return RequestResponses;
}

int RemoveRequestResponse(string str) {
    if( !RequestResponses[str] ) {
	return 0;
    }
    map_delete(RequestResponses, str);
    return 1;
}

mapping SetRequestResponses(mapping mp) {
    return (RequestResponses = expand_keys(mp));
}

mixed AddTalkResponse(mixed str, mixed val) {
    if (arrayp(str)) {
      foreach(string s in str) {
        TalkResponses[s] = val;
      }
    }
    if (stringp(str)) (TalkResponses[str] = val);
    return TalkResponses;
}

int RemoveTalkResponse(string str) {
    if( !TalkResponses[str] ) {
	return 0;
    }
    map_delete(TalkResponses, str);
    return 1;
}

mixed GetTalkResponse(string str) {
    return TalkResponses[str];
}

mapping GetTalkResponses() {
    return TalkResponses;
}

mapping SetTalkResponses(mapping mp) {
    return TalkResponses = expand_keys(mp);
}

varargs int SetWander(int speed, mixed *path, int recurse) {
    WanderSpeed = speed;
    if( path ) {
	WanderPath = path;
    }
    else {
	WanderPath = ({});
    }
    WanderRecurse = recurse;
}

mixed array GetWanderPath() {
    return WanderPath;
}

mixed array SetWanderPath(mixed array path) {
    return (WanderPath = path);
}

int GetWanderRecurse() {
    return WanderRecurse;
}

int SetWanderRecurse(int x) {
    return (WanderRecurse = x);
}

int GetWanderSpeed() {
    return WanderSpeed;
}

int SetWanderSpeed(int x) {
    return (WanderSpeed = x);
}

string SetClass(string cl) {
	mapping sk;
	string r = GetReligion();
	string c = ::SetClass(cl);
	if (cl == "priest") {
		sk = MORALITY_D->GetReligionSkills(r);
	  foreach (string skill, int rank in sk) {
       if (rank)  SetSkill(skill, 1, rank);
       if (!rank) RemoveSkill(skill);
    }		
	}
	return c;
}

string *SetReligion(mixed str...) {
	mapping sk;
	string cl = GetClass();
	string rl;
	string *n;
	n = ::SetReligion(str);
	rl = GetReligion();
	if (cl == "priest") {
		sk = MORALITY_D->GetReligionSkills(rl);
		foreach (string skill, int rank in sk) {
       if (rank)  SetSkill(skill, 1, rank);
       if (!rank) RemoveSkill(skill);
    }
	}
	return n;
}


/* ******************    /lib/npc.c events      **************** */
mixed eventAsk(object who, string str) {
    string cmd, args;
    
    if( !str || str == "" ) return 0;
    if( sscanf(str, "%s %s", cmd, args) != 2 ) {
	cmd = str;
	args = 0;
    }
    if( !CommandResponses[cmd] ) {
	if( !CommandResponses["default"] ) return 0;
	else if( stringp(CommandResponses["default"]) ) {
	    eventForce("speak " + CommandResponses["default"]);
	    return 1;
	}
	else return evaluate(CommandResponses["default"], who, cmd, args);
    }
    if( stringp(CommandResponses[cmd]) ) {
	eventForce("speak " + CommandResponses[cmd]);
	return 1;
    }
    return evaluate(CommandResponses[cmd], who, cmd, args);
}

varargs mixed eventReceiveEmote(object who, string verb, string info) {
    mixed val = EmoteResponses[verb];
    
    if( !val ) {
	return 0;
    }
    if( stringp(val) ) {
	eventSpeak(val);
	return 1;
    }
    return evaluate(val, this_player(), verb, info);
}

mixed eventRequest(object who, string str) {
    if( !str || str == "" ) return 0;
    if( !RequestResponses[str] ) {
	if( !RequestResponses["default"] ) return 0;
	else if( stringp(RequestResponses["default"]) ) {
	    eventForce("speak " + RequestResponses["default"]);
	    return 1;
	}
	else return evaluate(RequestResponses["default"], who, str);
    }
    if( stringp(RequestResponses[str]) ) {
	eventForce("speak " + RequestResponses[str]);
	return 1;
    }
    return evaluate(RequestResponses[str], who, str);
}

mixed eventTalkRespond(object who, object targ, int cls, string msg, string lang) {
    string resp;
    
  if (!sizeof(TalkResponses)) return 0;
    foreach(resp in keys(TalkResponses)) {
	if( resp == "default" ) continue;
	if( strsrch(lower_case(msg), resp) > -1 ) {
	    if( stringp(TalkResponses[resp]) ) {
		call_out( (: eventForce, "speak " + TalkResponses[resp] :), 0);
		return 1;
	    }
	    else if( evaluate(TalkResponses[resp], who, targ, msg, lang, cls) )
	      return 1;
	}
    }
    if( TalkResponses["default"] ) {
	if( stringp(TalkResponses["default"]) )
	  call_out( (: eventForce, "speak " + TalkResponses["default"] :), 0);
	else evaluate(TalkResponses["default"], who, targ, msg, lang, cls);
	return 1;
    }
    return 0;
}

mixed eventWander() {
    int fp;
    if (!sizeof(players())) return 0;
          
    if( !sizeof(WanderPath) ) {
	string *sorties;
	string tmp;

	sorties = ({});
	foreach(tmp in (string *)environment()->GetExits()) {
	    string dest, door;
	    
      if (!(environment()->GetExit(tmp))) continue;
	    if( !find_object(dest = (string)environment()->GetExit(tmp)) ) continue;
	    if( (door = (string)environment()->GetDoor(tmp)) && (int)door->GetClosed() ) continue;
	    if (!stringp(tmp)) continue;
	    sorties += ({ "go " + tmp });
	}
	foreach(tmp in (string *)environment()->GetEnters()) {
	    string dest, door;
	    
            if (!environment()) continue;
            if (!(environment()->GetEnter(tmp))) continue;
	    if( !find_object(dest = (string)environment()->GetEnter(tmp)) )
	      continue;
	    if( (door = (string)environment()->GetDoor(tmp)) && (int)door->GetClosed() ) continue;
	    if (!stringp(tmp)) continue;
	    sorties += ({ "enter " + tmp });
	}
	if( sizeof(sorties) ) {
	    eventForce(sorties[random(sizeof(sorties))]);
	    return 1;
	}
	else return 0;
    }
    if( arrayp(WanderPath[WanderMarker]) ) 
      foreach(mixed cmd in WanderPath[WanderMarker]) {
	  if( fp = functionp(cmd) ) {
	      if( fp != FP_OWNER_DESTED ) evaluate(cmd);
	  }
	  else eventForce(cmd);
      }
    else if( fp = functionp(WanderPath[WanderMarker]) ) {
	if( fp != FP_OWNER_DESTED ) evaluate(WanderPath[WanderMarker]);
    }
    else eventForce(WanderPath[WanderMarker]);
    WanderMarker++;
    if( WanderMarker >= sizeof(WanderPath) ) {
	WanderMarker = 0;
	if( !WanderRecurse ) WanderPath = ({});
    }
}

/********************** npc.c driver applies ************************/
static void create() {
    basenpc::create();
}

static void heart_beat() {
    if( !this_object() || !environment() ) {
        eventDestruct();
	return;
    }
    basenpc::heart_beat();
    if( !this_object() || GetDying() || !environment() ) {
	// no longer exist or in the middle of dying
	return;
    }
    if( !GetInCombat() ) { // Things to do when not in combat
	if( WanderSpeed ) { // Check if wandering
	    if( WanderCount >= WanderSpeed ) { // Time to wander
		WanderCount = 0;
		eventWander();
	    }
	    else {
		WanderCount++;
	    }
	}
    }
}
