#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"
int CheckVale();

static void create() {
   sentient::create();
   SetKeyName("hazy ghost");
   SetShort("a hazy ghost");
   SetId( ({ "ghost" }) );
   SetAdjectives( ({ "hazy" }) );
   SetLong("The ghost floats above the ground, suspended a few feet in "
           "mid-air.  He has the radiant figure of a dwarf, but is "
           "such a thin and transparent being that he is obviously "
           "not truly alive.");
   SetClass("rogue");
   SetProperty("vale_undead", 1);
    SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetLevel(16);
   SetGender("male");
   SetRace("ghost",1);
   SetStat("agility",20,4);
   SetStat("charisma",10,3);
   SetStat("coordination",25,3);
   SetStat("durability",35,2);
   SetStat("intelligence",25,3);
   SetStat("luck",30,3);
   SetStat("speed",20,3);
   SetStat("strength",35,2);
   SetStat("wisdom",30,2);
   AddLimb("torso",0,1,({ }) );
   AddLimb("head","torso",1,({ }) );
   AddLimb("right leg","torso",2,({ }) );
   AddLimb("left leg","torso",2,({ }) );
   AddLimb("right foot","right leg",4,({ }) );
   AddLimb("left foot","left leg",4,({ }) );
   AddLimb("left arm","torso",2,({ }) );
   AddLimb("right arm","torso",2,({ }) );
   AddLimb("left hand","left arm",4,({ }) );
   AddLimb("right hand","right arm",4,({ }) );
   SetMorality(-75);
   SetInventory( ([
                    VC_OBJ + "/c_candle" : 1,
                    VC_OBJ + "/c_coin_a" : 5+random(20),
               ]) );
  SetEncounter( (: CheckVale :) );
   SetNoCorpse(1);
   SetUndead(1);
}
int CheckVale() {
  object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
  return 1;
  }
return 0;
}
