/*    /daemon/emote.c
 *    From the Dead Souls V Object Library
 *    A centralized soul handler
 *    Created by Descartes of Borg 961207
 *    Version: @(#) soul.c 1.11@(#)
 *    Last modified: 96/12/15
 *
 *    GetChannelEmote() re-written by Zaxan@Aspirations
 */

#include <lib.h>
#include <dirs.h>
#include <pov.h>
#include <privs.h>
#include <daemons.h>

object GetEmote(string);
void eventReloadSouls();

inherit LIB_DAEMON;

private mapping Emotes = ([]);

string GetErrorMessage(string verb) {
	string m; object e;
	e = GetEmote(verb);
	if (!e) return "Unknown emote error.";
	m = e->GetErrorMessage();
	if (!m) return "You cannot " + verb + ".";
	return m;
}

object GetEmote(string verb) {
	object adv = load_object(ADVERBS_D);
	if (!Emotes[verb])
	  eventReloadSouls();
	return Emotes[verb];
}

string array GetEmotes() {
    return keys(Emotes);
}

string GetHelp(string arg) {
  string str;
  string *souls = keys(Emotes);
  souls = sort_array(souls, 1);
  
	str = "Your \"soul\" is a system of expressions you can use "
	    "to express how you are feeling.  Though it does not really "
	    "cause anything to happen, other people, including NPC's, may "
	    "react to your emotions, especially when they are violent or "
	    "negative.\n\n"
	    "Some soul commands allow you to express an adverb to give some "
	    "sort of emphasis to the expression.  Some commands are limited "
	    "to a certain set of adverbs, while most commands will allow you "
	    "to choose from the list of system wide adverbs given below.  "
	    "You may always use your racial adverb in any expression "
	    "allowing an adverb.  A racial adverb is simply a way of "
	    "emoting unique to your race, like \"smile gnomishly\".\n\n"
	    "For a list of soul commands, try <help feelings>.\n\n"
	    "The list of system adverbs are:\n";
  if (arg == "feelings") {
    str = "\n\nEmotes/Souls on Haven: \n";
    str += implode(souls, ", ");
  }
  return str;
}


string *GetRules(string emote) {
	return Emotes[emote]->GetRules();

}

int CanTarget(object who, string verb, object target, string rule) {

    if (target->GetInvis() > rank(who)) {
      return 0;
      }
    if( GetEmote(verb) ) {
	return 1;
    }
    else {
	return 0;
    }
}

mixed can_verb_rule(string verb, string rle) {
   object s = GetEmote(verb);
   if (!s) return 0;
   if (member_array(rle, s->GetRules()) == -1) {
   	return 0;
   	}
    return 1;
}

varargs mixed do_verb_rule(string verb, string rle, mixed args...) {
    object env = environment(this_player());
    object e = Emotes[verb];
    string r = e->GetMessage(rle);
    string adv = 0;
    
    switch( rle ) {
    case "":
	args = 0;
	adv = 0;
	break;

    case "LIV": case "at LIV": case "with LIV": case "to LIV":
    case "around LIV": case "on LIV":
    case "OBJ": case "at OBJ": case "with OBJ": case "to OBJ":
    case "LVS": case "at LVS": case "with LVS": case "to LVS":
    case "around LVS": case "on LVS":
	args = args[0];
	adv = 0;
	break;

    case "STR": case "for STR": case "about STR":
	adv = args[0];
	args = 0;
	break;

    case "STR LIV": case "STR at LIV": case "STR with LIV":
    case "STR around LIV": case "STR on LIV":
    case "for STR LIV": case "for STR to LIV":
    case "STR OBJ": case "STR at OBJ": case "STR with OBJ":
    case "STR LVS": case "STR at LVS": case "STR with LVS":
    case "STR around LVS": case "STR on LVS":
    case "for STR LVS": case "for STR to LVS":
	adv = args[0];
	args = args[1];
	break;

    case "LIV STR": case "at LIV STR": case "LIV of STR": case "with LIV STR":
    case "around LIV STR": case "on LIV STR":
    case "LIV for STR": case "to LIV for STR":
    case "OBJ STR": case "at OBJ STR": case "OBJ of STR": case "with OBJ STR":
    case "LVS STR": case "at LVS STR": case "LVS of STR": case "with LVS STR":
    case "around LVS STR": case "on LVS STR":
    case "LVS for STR": case "to LVS for STR":
	adv = args[1];
	args = args[0];
	break;

    default:
	this_player()->eventPrint("Unknown soul syntax.");
	return 1;
    }
    if( arrayp(args) ) {
	args = filter(args, (: objectp :));
    }
    if( adv ) {
	    string array matches = regexp(ADVERBS_D->GetAdverbs(), "^" + adv);
	    if( !sizeof(matches) ) {
		this_player()->eventPrint("You cannot " + verb + " " + adv +
					  "!");
		return 1;
	    }
	    adv = matches[0];
	send_messages(e->GetMessageVerbs(rle), e->GetMessage(rle), this_player(), args, env,
		      ([ "$adverb" : adv ]));
	if( args ) {
	    args->eventReceiveEmote(this_player(), verb, adv);
	}
    }
    else {
	send_messages(e->GetMessageVerbs(rle), e->GetMessage(rle), this_player(), args, env);
	if( args ) {
	    args->eventReceiveEmote(this_player(), verb);
	}
    }
    return 1;
}
static void create() {
  object ob;
  daemon::create();
  SetNoClean(1);
  eventReloadSouls();
}

void eventReloadSouls() {
	object ob, adv;
	parse_init();
	adv = load_object(ADVERBS_D);
  foreach(string emote in unguarded( (: get_dir, DIR_SOULS + "/" :) )) {
  	if (ob = load_object(DIR_SOULS + "/" + emote) ) {
  		if (ob)
  		Emotes[ob->GetVerb()] = ob;
    	}
  	}
  if (sizeof(Emotes))
  foreach(string verb in GetEmotes()) {
  	object e = GetEmote(verb);
    foreach(string rle in e->GetRules()) {
      parse_add_rule(e->GetVerb(), rle);
    }
  }
}

varargs mixed array GetChannelEmote(string emote, string parse, string args) {
    object e = GetEmote(emote);
    string r, *matches, t;
    mapping adverb = ([]);

    if(!e) return 0;
    if(!parse) parse = "";
    r = e->GetMessage(parse);
    if(!r) return 0;
//debug("a: " + args + " p " + parse + " r " + r);
    if(args) {
       
       matches = regexp(ADVERBS_D->GetAdverbs(), "^"+args);
       if(!sizeof(matches)) return 0;
       adverb = ([ "$adverb" : matches[0] ]);
    }
    return ({ e->GetMessageVerbs(parse), r, adverb });
}
