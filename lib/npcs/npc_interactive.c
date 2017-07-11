//
// The NPC Interactive lib
// An interactive object for NPCs.
// Created by Zaxan@Haven
//

#include <lib.h>
#include <daemons.h>
#include <objects.h>
#include <rooms.h>
#include <position.h>
#include <message_class.h>
#include <vision.h>
#include "include/npc_interactive.h"

inherit LIB_CONTAINER;
inherit LIB_OBJECT;
inherit LIB_PAGER;
inherit LIB_MESSAGES;
inherit LIB_INTERFACE;

private static int Setup, Brief = 0;

static void create() {
   object::create();
   messages::create();
   interface::create();
}

int Setup() {
   if(Setup) return 0;
   Setup = 1;
   interface::Setup();
}

void eventDescribeEnvironment(int brief) {
    object env;
    mixed tmp;
    string *shorts;
    string desc, smell, sound, touch;
    string weather;
    int i, maxi;

    if(!(env = environment(this_object()))) {
        eventPrint("You are nowhere.", MSG_ROOMDESC);
        return;
    }
    switch( i = GetEffectiveVision() ) {
    case VISION_BLIND:
	eventPrint("You are blind and can see nothing.");
	break;
    case VISION_TOO_DARK:
        eventPrint("It is much too dark to see.");
	break;
    case VISION_DARK:
	eventPrint("It is too dark to see.");
        break;
    case VISION_TOO_BRIGHT:
        eventPrint("It is much too %^YELLOW%^bright%^RESET%^ to see.");
	break;
    case VISION_BRIGHT:
        eventPrint("It is too %^YELLOW%^bright%^RESET%^ to see.");
        break;
    }
    if( !brief ) {
       if (i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM) {
	    desc = (string)env->GetObviousExits() || "";
	    desc = capitalize(env->GetInternalShort() || env->GetShort() || "")
		+ " [" + desc + "]\n";
	}
	else desc = "";
	if( i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM ) {
	    desc += (env->GetInternalLong() || env->GetLong() || "");
	}
	smell = env->GetSmell();
        sound = env->GetListen();
        touch = env->GetTouch();
        if (env->GetClimate() != "indoors" &&
            env->GetClimate() != "underground" &&
            !(env->GetProperty("no weather")) )
        weather = WEATHER_D->GetRoomWeather(env->GetClimate(), 
                                            env->GetDomain() );
    }
    else {
	if( i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM ) {
	    desc = (env->GetInternalShort() || env->GetShort() || "");
	    desc += " [" + (env->GetObviousExits() || "") + "]";
	}
	else desc = "";
    }
    if( desc ) eventPrint(desc, MSG_ROOMDESC);
    if( smell ) eventPrint("%^GREEN%^" + smell, MSG_ROOMDESC);
    if( sound ) eventPrint("%^CYAN%^" + sound, MSG_ROOMDESC);
    if( env->GetPoisonGas() > 5) 
        eventPrint("%^ORANGE%^There is a cloud of poison gas here!",
          MSG_ROOMDESC);
    if( touch ) eventPrint("%^YELLOW%^" + touch, MSG_ROOMDESC);
    if (weather) eventPrint("%^BLUE%^" + weather, MSG_ROOMDESC);
    desc = "";
    if( i == VISION_CLEAR || i == VISION_DIM || i == VISION_LIGHT ) {
	mapping lying = ([]);
        mapping sleeping = ([]);
	shorts = map(filter(all_inventory(env),
			    function(object ob) {
	                        if( living(ob) ) return 0;
                                if( (int)ob->GetInvis() )
				  return 0;
				if( (int)ob->isFreshCorpse() ) return 0;
				return 1;
	                    }), (: (string)$1->GetShort() :));
	foreach(string s in shorts) {
	    if( s ) {
		lying[s]++;
	    }
	}
	for(i=0, desc = 0, maxi = sizeof(shorts = keys(lying)); i<maxi; i++) {
	    string key = shorts[i];
	    int val = lying[shorts[i]];

	    if( val < 2 ) {
		if( !desc ) desc = "%^MAGENTA%^" +
				capitalize(key) + "%^RESET%^MAGENTA%^";
		else desc += key + "%^RESET%^MAGENTA%^";
	    }
	    else {
		if( !desc ) desc = "%^MAGENTA%^" +
				capitalize(consolidate(val, key)) +
		    "%^RESET%^MAGENTA%^";
		else desc += consolidate(val, key) +
		    "%^RESET%^MAGENTA%^";
	    }
	    if( i == maxi - 1 ) {
		if( maxi > 1 || val >1 )
		    desc += " are here.%^RESET%^\n";
		else desc += " is here.%^RESET%^\n";
	    }
	    else if( i == maxi - 2 ) {
		if( maxi == 2 ) {
		    desc += " and ";
		}
		else {
		    desc += ", and ";
		}
	    }
	    else desc += ", ";
	}
    }
    i = GetEffectiveVision();
    if( i == VISION_CLEAR || i == VISION_LIGHT || i == VISION_DIM ) {
	mapping lying = ([]), sitting = ([]), standing = ([]);
        mapping sleeping = ([]);
	object *obs;
	string key;
	int val;
	
	obs = filter(all_inventory(env), function(object ob) {
                                if( (int)ob->GetInvis() >= rank() )
                                         return 0;
					   if( living(ob) ) return 1;
					   if( (int)ob->isFreshCorpse() )
					     return 1;
	                                 }) - ({ this_object() });
	maxi = sizeof(shorts = map(obs, (: (string)$1->GetHealthShort() :)));
	foreach(object liv in obs) {
	    string s = (string)liv->GetHealthShort();
	    
	    if( !s ) continue;
	    if( creatorp(liv) || liv->GetPosition() == POSITION_STANDING) standing[s]++;
            else if( (liv->GetPosition() == POSITION_LYING &&
                       !liv->GetSleeping()) ||
                       liv->isFreshCorpse() )
	      lying[s]++;
	    else if( liv->GetPosition() == POSITION_SITTING ) sitting[s]++;
            else if (liv->GetSleeping()) sleeping[s]++;
	    else lying[s]++;
	}
        if( !desc ) {
            tmp = "";
        }
        else {
            tmp = desc;
        }
	desc = "";
	foreach(key, val in lying) {
	    if( val<2 ) desc += capitalize(key) + "%^RESET%^ is lying down.";
	    else desc += capitalize(consolidate(val, key)) +
		"%^RESET%^ are lying down.";
	    desc += "\n";
	}
        foreach(key, val in sleeping) {
           if (val < 2) desc += capitalize(key) + "%^RESET%^ is sleeping.";
            else desc += capitalize(consolidate(val, key)) +
              "%^RESET%^ are sleeping.";
           desc += "\n";
             }
	foreach(key, val in sitting) {
	    if( val<2 )
	      desc += capitalize(key) + "%^RESET%^ is sitting down.";
	    else desc += capitalize(consolidate(val, key)) +
		"%^RESET%^ are sitting down.";
	    desc += "\n";
	}
	foreach(key, val in standing) {
	    if( val<2 )
	      desc += capitalize(key) + "%^RESET%^ is here.";
	    else desc += capitalize(consolidate(val, key)) +
		"%^RESET%^ are here.";
	    desc += "\n";
	}
    }
    if( tmp ) {
	desc = tmp + desc;
    }
    if( sizeof(desc) ) {
	eventPrint(desc + "\n", MSG_ROOMDESC);
    }
}

int SetBriefMode(int brief) { 
   return (Brief = brief);
}

int GetBriefMode() { return Brief; }

int eventDestruct() {
    object ob;

    interface::eventDestruct();
    foreach(ob in deep_inventory(this_object())) {
	if( ob ) catch(ob->eventDestruct());
    }
    return object::eventDestruct();
}


void SetId(string *bogus) {
   object::SetId(bogus);
}

string *GetId() { return object::GetId(); }

int id(string str) {
    if(!str || !object::GetId()) return 0;
    else return member_array(lower_case(str), object::GetId()) != -1;
}

string SetKeyName(string str) {
    return object::SetKeyName(str);
}

string GetKeyName() { return object::GetKeyName(); }

string GetShort() {
   return object::GetShort();
}

void SetCapName(string str) {
    object::SetCapName(str);
}

string SetShort(string str) {
    return object::SetShort(str);
}

string SetLong(string str) {
    return object::SetLong(str);
}

string GetName() { return object::GetName(); }

varargs int GetInvis(object ob) { return object::GetInvis(ob); }

varargs mixed SetInvis(mixed level) {
  if (!intp(level)) return object::SetInvis(level);
  if (level > rank()) return object::SetInvis(rank());
  return (object::SetInvis(level));
}


mixed *GetCommands() {
    if( !((int)master()->valid_apply( ({ GetKeyName() }) )) ) return ({});
    else return commands();
}

void eventLoadObject(mixed *value, int recurse) { }

int GetRadiantLight(int ambient) {
    return (object::GetRadiantLight(ambient) +
	    container::GetRadiantLight(ambient));
}
