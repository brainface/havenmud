#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../cata.h"
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("skeletal warrior");
   SetShort("a skeletal warrior");
   SetId( ({ "skeleton", "warrior", "cata_npc" }) );
   SetAdjectives( ({ "skeletal" }) );
   SetLong("Years of rot and decay have left this skeletal"
           " warrior free from any flesh and meat on his bones."
           " He is tall and gaunt, yet looks as though he was"
           " extremely powerful when alive.");
   SetGender("male");
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
   SetClass("fighter");
   SetLevel(75);
   SetMorality(-75);
   SetMeleeDamageType(BLUNT);
   SetMeleeAttackString("bones");
   SetNoCorpse(1);
   SetDie("The skeletal warrior falls to the ground in a heap of dust.");
   SetInventory( ([
      CATA_OBJ "zweihander" : "wield zweihander",
      ]) );
   SetResistance(GAS, "immune");
   SetResistance(HUNGER, "immune");
   SetResistance(POISON, "immune");
}

varargs int eventDie(object who) {
  object key;

  key = new(CATA_OBJ "casket_key");
  if(!random(10)) {
    key->eventMove(environment());
  }
  return npc::eventDie(who);
}
