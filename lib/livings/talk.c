/*    /lib/talk.c
 *    from the Dead Souls  Object Library
 *    handles general yapping
 *    created by Descartes of Borg 951118
 *    Version: @(#) talk.c 1.5@(#)
 *    Last Modified: 96/10/08
 */

#include <talk_type.h>
#include <message_class.h>
#include "include/talk.h"
#include <lib.h>
#include <daemons.h>
#include <conditions.h>
#define MAXTELLHIST 40

inherit LIB_PERSIST;
int GetConditionFlag(int x);

int Viking = 0;
int SetViking(int x) { return Viking = x; }
int GetViking() { return Viking; }

int GetSkillLevel(string);
int GetStatLevel(string);
int AddSkillPoints(string, int);
string GetNativeLanguage();

private mixed *tellhist = ({ });
private mixed *sphist = ({ });
private void AddTellHist(string);
void AddRemoteTellHist(string);
mixed *GetTellHist();

int direct_ask_liv_str() { return 1; }

int direct_ask_liv_to_str() { return 1; }

int direct_request_str_from_liv() { return 1; }

int direct_say_to_liv() { return 1; }

int direct_say_to_liv_str() { return 1; }

int direct_whisper_to_liv() { return 1; }

int direct_whisper_in_wrd_to_liv() { return 1; }

int direct_whisper_to_liv_str() { return 1; }

int direct_whisper_in_wrd_to_liv_str() { return 1; }

int direct_whisper_to_liv_in_wrd_str() { return 1; }

varargs mixed CanSpeak(object target, string verb, string msg, string lang) {
    if( lang && (!GetLanguageLevel(lang) || !GetLanguageName(lang)) )
      return "You don't speak that language!";
    if( target ) {
	if( target == this_object() )
	  return "Are you really intent on talking to yourself?";
	if( userp(target) && !interactive(target) )
	  return (string)target->GetName() + " is net-dead.";
	if( (int)target->GetBlocked("tell") )
	  return (string)target->GetName() + " is blocking all tells.";
  }
  if (GetUndead()) {
  	if (GetUndeadType() == "ghost") {
  	  return "Ghosts can't talk!";
    }
  }

  
    return 1;
}

varargs mixed eventHearTalk(object who, object target, int cls, string verb,
			    string msg, string lang) {
    string tmp;
    int lvl;
    
    if (GetConditionFlag(CONDITION_PREVENT_HEAR)) return 0;
    if( lang && !newbiep() && lang != "common" && !creatorp()) {
      lvl = GetLanguageLevel(lang);
      msg = translate(msg, lvl, lang);
      }
    switch(cls) {
	case TALK_PRIVATE:
	if( target != this_object() ) return 0;
	if( verb == "reply" )
	    tmp = "%^BOLD%^RED%^" + (string)who->GetCapName() +
	    " replies,%^RESET%^ \"" + msg + "%^RESET%^\"";
	else tmp = "%^BOLD%^RED%^" + (string)who->GetCapName() +
	    " tells you,%^RESET%^ \"" + msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);
	AddTellHist(tmp);
	break;

	case TALK_SEMI_PRIVATE:
	if( target != this_object() ) return 0;
	tmp = "%^BOLD%^CYAN%^" + (string)who->GetName() + " whispers in " +
	    lang + " to you,%^RESET%^ \"" + msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);
	break;

	case TALK_LOCAL:
	if( target ) {
	    if( target != this_object() ) {
		if( msg[<1] == '?' ) tmp = (string)target->GetName();
		else tmp = "to " + (string)target->GetName();
		if( lang ) tmp += " in " + lang;
	    }
	    else {
		if( msg[<1] == '?' ) tmp = "you";
		else tmp = "to you";
		if( lang ) tmp += " in " + lang;
	    }
	    tmp = (string)who->GetName() + " " + pluralize(verb) + " " + tmp +
	      ", \"";
	    tmp = tmp + "%^BOLD%^CYAN%^\"" + msg + "%^RESET%^\"";
	    eventPrint(tmp, MSG_CONV);
	}
	else if( verb == "yell" ) {
	    tmp = "%^BOLD%^GREEN%^You hear a " + (string)who->GetGender()
		+ " " + (string)who->GetRace() + " yell in " + lang +
		" from a distance,%^RESET%^ \"" + msg + "%^RESET%^\"";
	    eventPrint(tmp, MSG_CONV);
	}
	else {
	    if( lang ) tmp = pluralize(verb) + " in " + lang;
	    else tmp = pluralize(verb);
	    tmp = (string)who->GetName() + " " + tmp + ", \"";
	    tmp = tmp + "%^BOLD%^CYAN%^" + msg + "%^RESET%^\"";
	    eventPrint(tmp, MSG_CONV);
	}
	break;

	case TALK_AREA:
	    tmp = "%^BOLD%^GREEN%^" + (string)who->GetName() + " yells in " +
		lang + ",%^RESET%^ \"" + msg + "%^RESET%^\"";
	    eventPrint(tmp, MSG_CONV);
	    break;

	case TALK_WORLD:
	    tmp = "%^BOLD%^BLUE%^" + (string)who->GetName() + " shouts in " +
		lang + ",%^RESET%^ \"" + msg + "%^RESET%^\"";
	    eventPrint(tmp, MSG_CONV); 
	break;

	default:
	return 0;
    }
    eventTalkRespond(who, target, cls, msg, lang);
    return 1;
}

mixed eventTalkRespond(object who, object targ, int cls, string msg, string lang) {
    return 1;
}

varargs mixed eventSpeak(object target, int cls, string msg, string lang) {
    object *bystanders;
    string verb, tmp;
    int x, cols;
    
    if( lang ) {
	msg = translate(msg, GetLanguageLevel(lang), lang);
	lang = GetLanguageName(lang);
    }
   if(Viking) {
   msg = viking(msg);
   lang = "viking";
   }
    cols = GetScreen()[0];
    if( msg[<1] != '?' && msg[<1] != '!' && msg[<1] != '.' )
      msg = capitalize(msg) + ".";
    else msg = capitalize(msg);
    switch( cls ) {
	case TALK_PRIVATE:
	tmp = "%^BOLD%^RED%^You tell " + (string)target->GetName() +
	    ",%^RESET%^ \"" + msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);	
	AddTellHist(tmp);
	target->eventHearTalk(this_object(), target, cls, "tell", msg);
	return 1;
	
	case TALK_SEMI_PRIVATE:
	if( !target ) tmp = "%^BOLD%^CYAN%^You whisper in " + lang +
			  ",%^RESET%^ \"" + msg + "%^RESET%^\"";
	else tmp = "%^BOLD%^CYAN%^You whisper in " + lang + " to " +
	  (string)target->GetName() + ",%^RESET%^ \"" + msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);	
	environment()->eventHearTalk(this_object(), target, cls, "whisper",
				     msg, lang);
	return 1;
	
	case TALK_LOCAL:
	if( msg[<1] == '?' ) verb = GetMessage("ask") || "ask";
	else if( msg[<1] == '!' ) verb = GetMessage("exclaim") || "exclaim";
	else {
	    verb = GetMessage("say") || "say";
	    if ((msg[<1] >= 'a' && msg[<1] <= 'z') ||
		(msg[<1] >= 'A' && msg[<1] <= 'Z')) msg = msg + ".";
	}
	if( target && msg[<1] == '?' ) {
	    tmp = "You " + verb + " " + (string)target->GetName();
	    if( lang ) tmp = tmp + " in " + lang;
	}
	else if( target ) {
	    tmp = "You " + verb + " to " + (string)target->GetName();
	    if( lang ) tmp = tmp + " in " + lang;
	}
	else {
	    tmp = "You " + verb;
	    if( lang ) tmp = tmp + " in " + lang;
	}
	tmp = tmp + ", \"%^BOLD%^CYAN%^" + msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);
	environment()->eventHearTalk(this_object(), target, cls, verb, msg,
				     lang);
	return 1;
	
	case TALK_AREA:
	tmp = "%^BOLD%^GREEN%^You yell in " + lang + ",%^RESET%^ \"" +
	    msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV);   	
	environment()->eventHearTalk(this_object(), target, cls, "yell", msg,
				     lang);
	break;

	case TALK_WORLD:
	tmp = "%^BOLD%^BLUE%^You shout in " + lang + ",%^RESET%^ \"" +
	    msg + "%^RESET%^\"";
	eventPrint(tmp, MSG_CONV); 		
	(users() - ({ this_object() }))->eventHearTalk(this_object(), target,
						       cls,"shout", msg, lang);
	return 1;
	
	default:
	return 0;
    }
}

void AddRemoteTellHist(string msg) {
	if (previous_object() != find_object(SERVICES_D)) return;
	AddTellHist(msg);
}

private void AddTellHist(string msg) {
	tellhist = tellhist[(sizeof(tellhist)-MAXTELLHIST+1)..(MAXTELLHIST-1)] + ({ ({ time(), msg }) });
}

mixed *GetTellHist() {
        if (this_player() != this_object() && !adminp(this_player()) ) 	{
		error("Illegal attempt to read tell history of " + identify(this_object()) +
		      " by " + identify(this_player()));
	}
	else return copy(tellhist);
}

static void create() {
	AddSave( ({ "tellhist", "sphist" }) );
}

void AddSPHist(string msg) {
	sphist = sphist[(sizeof(sphist)-MAXTELLHIST+1)..(MAXTELLHIST-1)] + ({ ({ time(), msg }) });
}

mixed *GetSPHist() {
        if (this_player() != this_object() && !adminp(this_player()) ) 	{
		      error("Illegal attempt to read tell history of " + identify(this_object()) +
		      " by " + identify(this_player()));
	}
	else return copy(sphist);
}
