// Amelia@Haven

#include <lib.h>
inherit LIB_NPC;
#include "balz.h"

static void create() {
   npc::create();
   SetKeyName("owl");
   SetShort("a white owl");
   SetId( ({ "white owl","owl" }) );
   SetLong("Covered in soft, white feathers, the owl is slightly "
	"sick and weakly.");
   
   SetRace("bird");
   SetClass("animal");
   SetLevel(2);
   
   SetCorpseItems( ([ B_OBJ + "/feather" : 2, ]) );
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
