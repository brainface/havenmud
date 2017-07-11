#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("janitor");
   SetShort("a youthful janitor");
   SetId( ({ "janitor" }) );
   SetAdjectives( ({ "youthful" }) );
   SetGender( ({ "male","female" })[random(2)]);
   SetLong(
     "Young in spirit and attempting to earn a small wage "
     "for " + possessive(this_object()) + " work, the "
     "youthful janitor is clean-cut and innocent."
   );
   SetRace("human");
   SetClass("rogue");
   SetLevel(1);
   
   SetMorality(200);
   SetCurrency("oros",5);
   SetAction(5, ({ 
     "!emote attempts to clean up the grime on the floor.",
     "!emote picks up some trash." 
   }) );
   SetInventory( ([
     PO + "/storagekey" : 1,
   ]) );
}
