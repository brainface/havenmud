#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("black raven");
   SetShort("a black raven");
   SetId( ({ "black raven","raven" }) );
   SetLong("The raven is slightly larger than the average crow, and "
           "stands cunningly on its two small feet.");
   SetRace("bird");
   SetClass("animal");
   SetLevel(3);
   SetGender("male");
}
