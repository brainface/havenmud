#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("elephant");
   SetShort("a forest elephant");
   SetId( ({ "elephant" }) );
   SetAdjectives( ({ "forest","small","smaller","male" }) );
   SetLong("Smaller than most elephants, this male is only 7 feet tall in "
           "the air, though still of an impressive size.  His ears are "
           "circular, more so than common elephants, and his tusks "
           "more slender as well.");
   SetGender("male");
   SetRace("elephant");
   SetClass("animal");
   SetLevel(3);
}
