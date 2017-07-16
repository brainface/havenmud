#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("grey fish");
   SetShort("a grey fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "grey","gray" }) );
   SetLong("Plain grey scales cover the fish's body, which shimmers "
           "with water.");
   switch(random(2)) {
      case 0:
      SetGender("male");
      break;
      case 1:
      SetGender("female");
      break;
   }
   SetRace("fish");
   SetClass("animal");
   SetLevel(1);
   SetMeleeAttackString("tail");
   SetMeleeDamageType(BLUNT);
}

void eventDie(object killer) {
   object blah;
   blah = new(H_OBJ + "fisha");
   blah->eventMove(this_object());
   ::eventDie(this_object());
}
