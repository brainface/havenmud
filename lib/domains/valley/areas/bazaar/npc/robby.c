//
// Robby the Refreshments Vendor
// Created by Athalie
//

#include <lib.h>
#include "../bazaar.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
   SetKeyName("robby");
   SetId( ({ "robby", "vendor", "robby the food vendor" }) );
   SetAdjectives( ({ "food" }) );
   SetShort("Robby the food vendor");
   SetLong("Robby whistles constantly and seems to not mind the "
     "terrible working conditions he is forced to endure here at his "
     "old booth. He smiles a lot and keeps his shabby clothes "
     "as clean as possible.");
   
   SetRace("human");
   SetClass("merchant");
   SetLevel(6);
   SetGender("male");
   SetMorality(-25);
   SetAction(2, ({
     "!emote wiggles his eyebrows at you.",
     "!speak My, but don't you look hungry! Come and try our specialties!",
     "!emote winks.",
   }) );
   SetLocalCurrency("rupies");
   SetMenuItems( ([
     "meat" : BAZAAR_OBJ "meat_stick",
     "water" : BAZAAR_OBJ "water_cup",
   ]) );
   SetCurrency("rupies",random(40));
   SetLocalCurrency("rupies");
}
