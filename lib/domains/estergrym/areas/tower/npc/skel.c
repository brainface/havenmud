#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("skeleton",1);
   SetRace("skeleton",1);
   SetStat("charisma",1,5);
   SetStat("coordination",20,3);
   SetStat("luck",5,5);
   SetStat("wisdom",5,2);
   SetStat("durability",30,2);
   SetStat("intelligence",5,2);
   SetStat("strength",51,2);
   SetStat("agility",19,4);
   AddLimb("spine vertebrae",0,1,({ }) );
   AddLimb("skull","spine vertebrae",1,({ }) );
   AddLimb("rib cage","spine vertebrae",1,({ }) );
   AddLimb("scapula","spine vertebrae",2,({ }) );
   AddLimb("left humerus","scapula",4,({ }) );
   AddLimb("right humerus","scapula",4,({ }) );
   AddLimb("left radius and ulna","left humerus",4,({ }) );
   AddLimb("right radius and ulna","right humerus",4,({ }) );
   AddLimb("left carpals","left radius and ulna",5,({ A_WEAPON }) );
   AddLimb("right carpals","right radius and ulna",5,({ A_WEAPON }) );
   AddLimb("hip","spine vertebrae",2,({ }) );
   AddLimb("left femur","hip",3,({ }) );
   AddLimb("right femur","hip",3,({ }) );
   AddLimb("left patella","left femur",4,({ }) );
   AddLimb("right patella","right femur",4,({ }) );
   AddLimb("left tibia and fibula","left patella",4,({ }) );
   AddLimb("right tibia and fibula","right patella",4,({ }) );
   AddLimb("left tarsals","left tibia and fibula",5,({ }) );
   AddLimb("right tarsals","right tibia and fibula",5,({ }) );
  SetGender("male");
  SetClass("rogue");
  SetLevel(75);
  SetKeyName("skeleton");
  SetId( ({ "skeleton"}) );
  SetShort("a summoned skeleton");
  SetAdjectives( ({ "summoned", "undead" }) );
  SetLong("This is a generic humanoid skeleton with bleached white bones. "
          "He is missing most of his teeth and the remaining are split or "
          "have been broken off. His body has some dents and scratches on "
          "the surface which is sparkling slightly.");
  SetUndead(1);
  SetDie("The skeleton crumbles into dust."); 
  SetMorality(-25);
  SetCombatAction(5, ({ 
    "!guard kilwrath",
    "!emote attempts to bite at your neck!",
	}) ); 
  SetStat("charisma", 201, 1);
  SetFriends(({
               TOWER_NPC+"necromancer",
               TOWER_NPC+"shrieker",
  }));
  SetResistance(POISON, "high");  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high"); 
  SetNoCorpse(1);
  }