// Town Watchman just average citizens that 
// serve their town with a tour of duty in the 
// watch

#include <lib.h>
#include "../drazh.h"


inherit LIB_NPC;

int type = random(2);
string CheckSetShort();

int CheckWanted();
#include "../wanted.h"

static void create() {
  npc::create();
  SetId( ({"skaven","watchman","wander"}) );
  SetKeyName("watchman");
  SetTown("Drazh");
  SetReligion("Soirin"); 
  SetRace("skaven");
  SetGender("male");
  SetLimit(6); 
  SetClass("fighter");
  SetLevel(15 + random(10));
  SetWander(5);
  SetMorality(-1000);
  SetEncounter( (: CheckWanted :) );
  SetAction(3, ({
     "!yawn",
     "!sneer",
     "!emote stands at attention.",
     }) );
  SetCombatAction(4, ({
     "!say Die!",
     "!yell Die!!",
     "!disorient",
     "!disarm",
     }) );
  SetFriends( ({
     "skaven","watchman",
	 }) );

  if (type == 0) {
  SetAdjectives( ({ "strong", "skaven" }) );
  SetShort("a strong skaven watchman");
  SetLong(
     "This strong looking skaven is one of the watchmen of the city. He patrols "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
     );
  SetInventory( ([
     V_OBJ + "axe"        : 2,
     V_OBJ + "scale_mail" : "wear armour",
	   V_OBJ + "lpants"     : "wear pants",
     ]) );
  call_out((: eventForce, "wield 1st axe" :),1 );
  call_out((: eventForce, "wield axe" :),1 );
  }

  else if (type == 1) {
  SetAdjectives( ({ "agile","skaven" }) );
  SetShort("an agile skaven watchman");
  SetLong(
     "This agile looking skaven is one of the watchmen of the city. He patrols "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
      );
  SetInventory( ([
     V_OBJ + "scimitar"    : "wield sword in right claw",
     V_OBJ + "hooded_robe" : 
      "wear robe on torso and right leg and right arm and left arm and left leg",
	   V_OBJ + "lpants"      : "wear pants",
	   V_OBJ + "buckler"     : "wear buckler on left arm",
     ]) );
  } 
}

int CheckWanted() {
  if (this_player()->GetInvis()) return 0;
  if (!userp(this_player())) return 0;
  if (member_array(this_player()->GetKeyName(), keys(Crimes)) != -1) {
    eventForce("follow " + this_player()->GetKeyName());
    eventForce("yell Suffer, Criminal!");
     SetAttack(this_player());
    return 1;
  }
  if(this_player()->GetProperty("invader")) {
     eventForce("yell Invaders!");
     SetAttack(this_player());
     return 1;
  }
}
