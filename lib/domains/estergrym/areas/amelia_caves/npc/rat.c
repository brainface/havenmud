// Amelia@Haven

#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../cave.h"
 
static void create() {
   npc::create();
   SetKeyName("rat");
   SetId( ({ "rat" }) );
   SetAdjectives( ({ "wet","shivering" }) );
   SetShort("a shivering rat");
   SetLong(
     "Gleaming red eyes glare out at the world from the "
     "wet, shivering rat.  He isn't very impressive."
   );
   SetRace("rodent");
   SetClass("animal");
   SetLevel(2);
   SetGender("male");
   
   SetMeleeAttackString("claws");
   SetMeleeDamageType(PIERCE);
}
 
 
void eventDie(object killer) {
    object item;
  item = new( C_OBJ + "claw");
  item->eventMove(this_object());
  npc::eventDie(killer);
}
