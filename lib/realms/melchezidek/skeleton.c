#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("white skeleton");
   SetShort("a white skeleton");
   SetId( ({ "skeleton" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("This skeleton has immaculate white bones. They look strong and"
           " durable. The skeleton is large and humanoid is appearance"
           " but what race it came from prior to its current state is"
           " anyones guess.");
   SetGender("male");
   SetRace("skeleton",1);
   SetFriends( ({ "rocklock" }) );
   SetStat("charisma",1,5);
   SetStat("coordination",20,3);
   SetStat("luck",5,5);
   SetStat("wisdom",5,2);
   SetStat("durability",250,1);
   SetStat("intelligence",5,2);
   SetStat("strength",100,1);
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
   SetClass("horror");
   SetLevel(75);
   SetMorality(0);
   SetUndead(1);
   SetMeleeDamageType(BLUNT);
   SetMeleeAttackString("bones");
   SetFirstActions( ({
   "guard rocklock",
   }) );
   SetCombatActions(50, ({
     "disorient",
     "guard rocklock",
     "emote rattles uneasily as he attacks.",
     "emote stumbles briefly.",
   }) );
}
