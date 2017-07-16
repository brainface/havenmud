// A bottom feeder in the chain of devils
// Demon Invasion of Soleil
// Coded by: Unknown
// Rewritten: Laoise, 2005

#include <lib.h>
#include <armour_types.h>
inherit LIB_INVADER;

int CheckSoleil();

static void create() {
  invader::create();
  SetKeyName("lemure");
  SetShort("a slimy lemure");
  SetId( ({ "lemure", "devil", "demon_inv" }) );
  SetAdjectives( ({ "slimy" }) );
  SetLong(
    "This is a lemure, one of the damned souls stuck for "
    "all eternity in the Lower Planes. Its pitiful body "
    "has only a slimy, muck-like lower half with two "
    "protrusions that pass as arms and a half formed head with "
    "large and unclosing eyes of solid black."
  );
  SetRace("lemure",1);
  AddLimb("torso", 0, 1);
  AddLimb("right arm", "torso", 2);
  AddLimb("left arm", "torso", 2);
  AddLimb("head", "torso", 1);
  AddLimb("right hand", "right arm", 4, A_WEAPON);
  AddLimb("left hand", "left arm", 4, A_WEAPON);
  SetStat("strength", 15, 2);
  SetStat("durability", 15, 2);
  SetStat("agility", 2, 4);
  SetStat("coordination", 2, 4);
  SetClass("rogue");
  SetLevel(16);
  SetEncounter( (: CheckSoleil :) );
  SetFriends( ({ "demon_inv" }) );
  SetWanderSpeed(5);
  SetWanderPath( ({ 
    "enter hall", "go east", "go out", "go west", "go down",
    "go down", "go north", "go south", "go west", "go east",
    "enter inn", "go out", "go up", "go up", "go west", 
    "go west", "go east", "go east", "go east", "go east",
    "go west", "go west",
  }) );
  SetWanderRecurse(1);
}

int CheckSoleil() {
  object who = this_player();
  if(!userp(who) && !(who->GetProperty("invader"))) {
    SetAttack(who);
    return 1;
  }
return 0;
}
