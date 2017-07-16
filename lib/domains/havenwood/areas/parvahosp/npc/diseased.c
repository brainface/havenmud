#include <std.h>
#include <lib.h>
#include "../ph.h"
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("patient");
   SetShort("a diseased patient");
   SetId( ({ "patient" }) );
   SetAdjectives( ({ "disease" }) );
   SetGender( ({ "male","female" })[random(2)]);
   SetLong(
     "Best kept in quarantine from the rest of the patients, this "
     "poor human is inflicted with a terrible disease. Wasting "
     "away from sickness, " + nominative(this_object()) + " can "
     "barely move."
   );
   SetRace("human");
   SetClass("rogue");
   SetLevel(1);
   
   SetCurrency("oros",5);
   SetInventory( ([
     STD_GERMS + "pflu" : 1,
   ]) );
   SetAction(1, ({ 
     "!emote moans.","!emote attempts to move to drink some "
     "water and collapses onto the bed." 
   }) );
   SetCombatAction(1, ({ 
     "!whimper" 
  }) );
}
