#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("adult picnicker");
   SetMorality(10);
   SetShort("an adult picnicker");
   SetId( ({ "adult","picnicker","muezzin" }) );
   SetAdjectives( ({ "adult","muezzin" }) );
   SetLong("The muezzin adult is of medium height and average build, "
           "with little to distinguish " + reflexive(this_object()) +
           " from any others.  Something about " + objective(this_object())
           + " shows that " + nominative(this_object()) + " is here for "
           "joy and fun.");
   switch(random(2)) { 
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("muezzin");
   SetClass("rogue");
   SetLevel(20+random(4));
   SetMeleeAttackString("fists");
   SetMeleeDamageType(BLUNT);
   SetInventory( ([
                    H_OBJ + "basket" : 1,
                    H_OBJ + "sandwich" : 1,
                    H_OBJ + "juice" : 1,
                    H_OBJ + "fruit" : 1+random(3),
                    H_OBJ + "tablec" : random(2),
               ]) );
   SetMorality(200);
}
