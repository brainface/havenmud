#include <lib.h>
#include <damage_types.h>
inherit LIB_SENTIENT;
#include "../castle.h"
int CheckVale();

static void create() {
   sentient::create();
   SetKeyName("white skeleton");
   SetShort("a white skeleton");
   SetId( ({ "skeleton" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("The skeleton is clear of rotting flesh, but somehow still "
           "seems to be animated.  His bones are frail and his polished "
           "white color almost gleams in the low light.");
   SetGender("male");
   SetProperty("vale_undead", 1);
   SetRace("skeleton",1);
   SetStat("charisma",1,5);
   SetFriends( ({ "shade", "skeleton", "ghost", "zombie", "spook", "ghoul", "phantom" }) );
   SetStat("coordination",20,3);
   SetStat("speed",23,2);
   SetStat("luck",5,5);
   SetStat("wisdom",5,2);
   SetStat("durability",30,2);
   SetStat("intelligence",5,2);
   SetStat("strength",51,1);
   SetStat("agility",19,4);
   AddLimb("spine vertebrae",0,1,({ }) );
   AddLimb("skull","spine vertebrae",1,({ }) );
   AddLimb("rib cage","spine vertebrae",1,({ }) );
   AddLimb("scapula","spine vertebrae",2,({ }) );
   AddLimb("left humerus","scapula",4,({ }) );
   AddLimb("right humerus","scapula",4,({ }) );
   AddLimb("left radius and ulna","left humerus",4,({ }) );
   AddLimb("right radius and ulna","right humerus",4,({ }) );
   AddLimb("left carpals","left radius and ulna",5,({ }) );
   AddLimb("right carpals","right radius and ulna",5,({ }) );
   AddLimb("hip","spine vertebrae",2,({ }) );
   AddLimb("left femur","hip",3,({ }) );
   AddLimb("right femur","hip",3,({ }) );
   AddLimb("left patella","left femur",4,({ }) );
   AddLimb("right patella","right femur",4,({ }) );
   AddLimb("left tibia and fibula","left patella",4,({ }) );
   AddLimb("right tibia and fibula","right patella",4,({ }) );
   AddLimb("left tarsals","left tibia and fibula",5,({ }) );
   AddLimb("right tarsals","right tibia and fibula",5,({ }) );
   SetLimit(3);
   SetClass("rogue");
   SetLevel(15);
   SetWander(23);
   SetMorality(-75);
   SetUndead(1);
   SetEncounter( (: CheckVale :) );
   SetMeleeDamageType(BLUNT);
   SetMeleeAttackString("bones");
}

eventDie(object killer) {
   object item;
   item = new(VC_OBJ + "/c_bone_w");
   item->eventMove(this_object());
   ::eventDie(killer);
}
int CheckVale() {
  object who = this_player();
  if (!(who->GetProperty("vale_undead"))) {
    SetAttack(who);
  return 1;
  }
return 0;
}
