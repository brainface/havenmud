//  Modified by Zalbar
//  7-2004

#include <lib.h>
#include "../drazh.h"
inherit LIB_NPC;

int type = random(2);
string CheckSetShort();

int CheckWanted();
#include "../wanted.h"

static void create() {
  npc::create();
  SetKeyName("watchman");
  SetId( ({"watchman","skaven"}) );
  SetRace("skaven");
  SetGender("male");
  SetClass("fighter");
  SetLevel(20 + random(10)); 
  SetMorality(-1000);
  SetAction(3, ({
     "!yawn",
     "!emote stands at attention.",
	 }) );
  SetCombatAction(4, ({
     "!say Die!",
     "!yell Die!!",
	 }) );
  SetEncounter( (: CheckWanted :) );
  SetFriends( ({
     "skaven","watchman",
	 }) );


  if (type == 0) {
  SetAdjectives( ({"agile","skaven"}) );
  SetShort("an agile skaven watchman");
  SetLong(
     "This agile looking skaven is one of the watchmen of the city. He guards "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
	   );
  SetInventory( ([ 
     V_OBJ + "axe"              : "wield axe",
     V_OBJ + "scale_mail"       : "wear armour",
	   V_OBJ + "lpants"           : "wear pants",
	   ]) );
  }

  else if (type == 1) {
  SetAdjectives( ({"strong","skaven"}) );
 
  SetShort("a strong skaven watchman");
  SetLong(
     "This strong looking skaven is one of the watchmen of the city. He guards "
     "the streets, enforcing the law to all of those who live in and visit "
     "the town. "
     );
  SetInventory( ([
     V_OBJ + "longsword"        : "wield sword",
     V_OBJ + "scale_mail"       : "wear armour",
	   V_OBJ + "lpants"           : "wear pants",
	   "/std/weapon/melee/cestus" : "wield cestus"
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

