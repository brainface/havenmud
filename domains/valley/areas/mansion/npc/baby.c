/* a small baby for the mansion
     kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("baby");
  SetShort("a tiny baby");
  SetId( ({ "baby"}) );
  SetAdjectives( ({"tiny"}) );
  SetLong("This tiny baby is just adorable and is certainly too young "
          "to do any harm to anyone. He is also too young to be the "
          "child of the owners of the mansion and is more likely one of "
          "the guest's children.");
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(1);
  SetMorality(700);
  SetAction(6,
     ({ "The child coos at you with loving eyes.", 
        }) );
  SetCombatAction(25,
     ({ "The child cries out in terrible distress."}) );
  }
