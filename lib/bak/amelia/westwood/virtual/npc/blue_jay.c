#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("blue jay");
   SetShort("a blue jay");
   SetId( ({ "blue jay","jay" }) );
   SetLong("The blue jay's feathers are mostly black, but have a "
           "dark blue tint to them that gives the blue jay its name.");
   SetRace("bird");
   SetGender("male");
   SetLevel(2);
   SetClass("animal");
}
