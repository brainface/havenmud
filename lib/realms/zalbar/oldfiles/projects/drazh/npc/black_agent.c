// Modified by Dahaka
// Aug 2004

#include <lib.h>
#include <std.h>
#include "../drazh.h"

inherit LIB_NPC;
int CheckWanted();
#include "../wanted.h"

static void create() {
  ::create();
  SetKeyName("velsk");
  SetTown("Drazh");
  SetReligion("Soirin");
  SetId( ({"velsk","figure","skaven","wander"}) );
  SetAdjectives( ({"dark","shadowy"}) );
  SetShort("a dark shadowy figure");
  SetLong(
     "This dark shadowy figure stands around the town, remaining unnoticed "
     "by the average traveller to this town. His hooded robe covers his "
     "entire body, except for his long snout that sticks out slightly from "
     "under his hood."
     );
  SetGender("male");
  SetRace("skaven");
  SetClass("rogue");
  SetClass("fighter");
  SetLevel(125);
  SetMorality(-2000);
  SetInventory( ([
     V_OBJ + "hooded_robe"  : 
      "wear robe on torso and left arm and left leg and right arm and right leg",
     V_OBJ + "lpants"       : "wear pants",
     V_OBJ + "lvest"        : "wear vest",
     V_OBJ + "double_knife" : 2,
     ]) );
  SetWander(5);
  SetCurrency("roni",random(6000));
  SetLimit(1);
  SetFriends( ({"skaven","watchman"}) );
  SetAction(1, ({
     "The shadowy figure walks around quietly."
   }) );
  SetCombatAction(10, ({
     "!disorient",
     "!yell Enemies! Kill them all!",
     "!growl violently",
     "!say Die!"
     "!disorient",
     "!disarm",
   }) );
  SetFirstCommands( ({
     "wield 1st knife",
     "wield knife",
     }) );
}

int CheckWanted() {
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
