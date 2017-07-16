// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

static void create() {
   npc::create();
   SetProperty("enchforestnoleave",1);
   SetKeyName("owl");
   SetShort("a white owl");
   SetId( ({ "white owl","owl" }) );
   SetLong("Soft white feathers cover the owl.");
   SetLevel(1);
   SetClass("animal");
   SetRace("bird");
   SetInventory( ([  B_OBJ + "/feather" : "wear feather" ]) );
   SetAction(5, "The owl hoots eerily.");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
}
