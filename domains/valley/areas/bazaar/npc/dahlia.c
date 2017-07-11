//
// Dahlia the carpet vendor
// Created by Athalie
//

#include <lib.h>
#include "../bazaar.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
   SetKeyName("dahlia");
   SetId( ({ "dahlia", "vendor", "dahlia the carpet vendor" }) );
   SetShort("Dahlia the carpet vendor");
   SetLong("Dahlia is quite tall for a sprite, and has very short, wispy hair. "
     "She doesn't seem to be very happy to be working at the bazaar. "
     "Her attire, while clean, is faded and worn out.");
   
   SetRace("sprite");
   SetClass("rogue");
   SetLevel(5);
   SetGender("female");
   SetMorality(-75);
   SetAction(5, ({
     "!emote straightens the stacks of rugs.",
     "!speak can I interest you in a new carpet of some kind?",
   }) );
   SetLocalCurrency("rupies");
   SetMenuItems( ([
     "rug" : BAZAAR_OBJ + "rug",
   ]) );
   SetCombatAction(5, ({
     "!emote looks annoyed.",
     "!speak leave me alone!",
   }) );
}
