#include <lib.h>
#include <damage_types.h>
inherit LIB_NPC;
#include "../hiker.h"

static void create() {
   npc::create();
   SetProperty("hikernoleave",1);
   SetKeyName("rainbow fish");
   SetShort("a rainbow fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "rainbow" }) );
   SetLong("The fish has rather large teeth and a versatile mouth, "
           "showing that it probably attacks things with it.  It "
           "is pretty large.");
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
   SetLevel(1+random(2));
   SetMeleeAttackString("teeth");
   SetMeleeDamageType(PIERCE);
}

void eventDie(object killer) {
   object blah, blah2;
/* File doesn't exist
   blah = new(H_OBJ + "teeth");
*/
   blah2 = new(H_OBJ + "fishb");
/*
    blah->eventMove(this_object());
*/
   blah2->eventMove(this_object());
   ::eventDie(killer);
}
