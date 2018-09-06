/*    /lib/fishing.c
 *    from the Dead Souls LPC Library
 *    a room which allows fishing in it
 *    created by Descartes of Borg 950529
 *    Version: @(#) fishing.c 1.7@(#)
 *    Last modified: 96/10/30
 */

#include <lib.h>
#include "include/fishing.h"

inherit LIB_ROOM;

static private mapping Fishing, Fish, RareFish;

// mahk 2018: effectively removing ability to change these
// i swear to god whoever wrote this was trying to make
// a fishing simulator, and fishing just isn't that 
// interesting. So every room is going to have the same
// chance to find fish, the same max # players fishing,
// and you'll fish at the same speed.
static private int MaxFishing = 10;
static private int Speed = 5;
static private int Room_Chance = 25;

static void create() {
    room::create();
       
    Fish = ([]);
    RareFish = ([]);
    Fishing = ([]);
}

static void heart_beat() {
  mapping tmp;
  object pole;
  string fisher;
  ::heart_beat();
  tmp = Fishing;
  Fishing = ([]);

  // Check legality: does fisher exist, does pole exist
  foreach(fisher, pole in tmp) {
    object ob;

    if( !fisher ) { continue; }
    ob = present(fisher);
    if (!ob) {     
      foreach(object ship in filter(all_inventory(), (: vehiclep :) )) {
        if (ob = present(fisher, ship)) break;
      }
    }
    if (!ob) {  continue; }
    if( !living(ob) || !pole ) continue;
    if( !present(pole, ob) ) continue;
    if( (int)pole->GetBroken() ) continue;
    if( (object)ob->GetInCombat() ) {
      message("my_action", "You are no longer fishing.", ob);
      continue;
    }
    Fishing[fisher] = pole;
  }
  
  foreach(fisher, pole in Fishing) {
    object who;
    object fish;
    // hey here's crazy talk how about we name variables meaningful fucking
    // names because fuck if i know what x and y are supposed to be
    int chance;
    int rod_chance, fish_amount, fish_selector;
    int fish_selector;
    
    rod_chance = (int)pole->eventFish(who);
    
    // hey am i fishing up a rare let's find out 
    if (!random(2) && random(who->GetLuck()+who->GetSkill("fishing")+ rod_chance) > random(100)) {
      fish = GetRandomRareFish();
    } else {
      // nope just a normal boring (food) fish
      fish = GetRandomFish();
    }
      
    // if this room is impossible to fish, or if using a non-fishing 
    // device, no fishing can really occur
    rod_chance = (int)pole->eventFish(who);
    
    if( !Room_Chance || !rod_chance ) {
      chance = 0;
    } else {
      chance = eventCheckSkill(who->GetSkillLevel("fishing"), fish->GetLevel()*2, Room_Chance + rod_chance, 0);
    }
   
    if( !chance ) {
      send_messages("cast", "$agent_name $agent_verb again, hoping "
      "for better luck.", who, 0, environment(who));
      continue;
    }

    if (who->GetSleeping()) {
      who->SetSleeping(0);
      who->eventPrint("You are awakened by a tug on your pole.");
    }     
    send_messages("struggle", "$agent_name $agent_verb with "
     "something on $agent_possessive " +
     pole->GetKeyName() + ".", who, 0, environment(who));
    call_out( (: eventCatch, who, fish, pole :), 1 );
  }
}

/*
 * "Can I start fishing here?"
 * Note that the verb is fish, not cast.
 */
mixed CanCast(object who, string where) {
    if( (int)this_player()->GetInCombat() ) 
      return "You are too busy to fish!";
    if( Fishing[(string)this_player()->GetKeyName()] )
      return "You are already fishing!";
    if( GetMaxFishing() <= sizeof(Fishing) ) 
      return "It is too crowded here to fish.";
    return 1;
}

/*
 * "Can i stop fishing here?"
 */
mixed CanStop(object who, string str) {
    if( str != "fishing" ) return 0;
    str = (string)this_player()->GetKeyName();
    if( !Fishing[str] ) return "You are not fishing!";
    return 1;
}

/*
 * Start fishing, inform room
 */
mixed eventCast(object who, object pole, string str) {
    mixed err;
    send_messages(({ "cast", "start" }),
		  "$agent_name $agent_verb $agent_possessive " + pole->GetKeyName() + " and $agent_verb fishing.", who, 0, environment(who));
    SetFishing(who, pole);
    return 1;
}
    
/*
 * yay catchfish
 */
static void eventCatch(object who, object fish, object pole) {
    if( !who ) return;
    if( !pole || !present(pole, who) ) {
	    message("my_action", "Having given up " + (string)pole->GetShort() + 	", you lose your catch!", who);
	    return;
      }
    if( !((int)pole->eventCatch(who, fish)) ) return;
    RemoveFishing(who);
    who->AddExperience((fish->GetLevel() * who->GetSkillLevel("fishing")) / 5);
    message("my_action", "You find " + (string)fish->GetShort() + " on " +
	    (string)pole->GetShort() + "!", who);
    message("other_action", (string)who->GetName() + " finds " + 
	    (string)fish->GetShort() + " on " + (string)pole->GetShort() + 
	    "!", environment(who), ({ who }));
    if( !((int)fish->eventMove(who)) ) {
	message("my_action", "You drop " + (string)fish->GetShort() + "!",
		who);
	message("other_action", (string)who->GetName() + " drops " +
		(string)fish->GetShort() + "!", environment(who), ({ who }) );
	food->eventMove(environment(who));
    }
}

/*
 * Inform room/player that they stopped fishing
 */
mixed eventStop(object who, string str) {
    RemoveFishing(this_player());
    message("my_action", "You stop fishing.", who);
    message("other_action", (string)who->GetName() + " stops "
	    "fishing.", environment(who), ({ who }) );
    return 1;
}

/*
 * Mapping of normal fish in the room
 * ( ([ STD_FISH "bass", 1 ]) etc. 
 * The number does nothing and exists for legacy reasons
 */
mapping SetFish(mapping mp) { return (Fish = mp); }

/*
 * Mapping of rare fish in the room
 * ( ([ STD_FISH "magic_bass", 1 ]) etc. 
 * The number does nothing and exists for legacy reasons
 */
mapping SetRareFish(mapping mp} { return (RareFish = mp); }

/*
 * Get the mapping of normal fish
 */
mapping GetFish() { return Fish; }
/*
 * Get the mapping of rare fish
 */
mapping GetRareFish() {return RareFish;}

/*
 * Return some random normal fish (to be caught)
 */
string GetRandomFish() {
  return Fish[random(len(Fish))];
}

/*
 * return some random rare fish (to be caught)
 */
string GetRandomRareFish() {
  return RareFish[random(len(RareFish))];  
}

/*
 * Add a living to the list of fishers in the room
 */
mapping SetFishing(object who, object pole) {
    if( !living(who) ) return Fishing;
    if( !query_heart_beat() ) set_heart_beat(Speed);
    Fishing[(string)who->GetKeyName()] = pole;
    return Fishing;
}

/*
 * remove a living from the list of fishermen in the room.
 */
mapping RemoveFishing(object who) {
    string str;

    if( !who ) return Fishing;
    if( Fishing[str = (string)who->GetKeyName()] ) 
      map_delete(Fishing, str);
    if( !sizeof(Fishing) ) set_heart_beat(0);
    return Fishing;
}

// mahkefel 2018: deprecating

int SetMaxFishing(int x) { return (MaxFishing = x); }
int GetMaxFishing() { return MaxFishing; }
int SetSpeed(int x) { return (Speed = x); }
int GetSpeed() { return Speed; }
int SetChance(int x) { return (Room_Chance = x); }
int GetChance() { return Room_Chance; }
int AddFish(string fish, int x) {
    if( !Fish[fish] ) Fish[fish] = x;
    else Fish[fish] += x;
    return Fish[fish];
}
mapping RemoveFish(string fish) {
    if( Fish[fish] ) map_delete(Fish, fish);
    return Fish;
}

