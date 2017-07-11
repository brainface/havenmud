//
// Lilah the flower vendor
// Created by Athalie
//
#include <lib.h>
#include "../bazaar.h"
inherit LIB_BARKEEP;

static void create() {
  barkeep::create();
   SetKeyName("lilah");
   SetId( ({ "lilah", "vendor", "lilah the flower vendor" }) );
   SetAdjectives( ({ "flower" }) );
   SetShort("Lilah the flower vendor");
   SetLong("Lilah looks bored most of the time, but occasionally she finds "
     "reason to perk up. She enjoys having customers, because it adds "
      "a little excitement to her otherwise boring job. Her long blonde hair "
     "tumbles over her shoulders quite attractively, which draws attention "
      "away from her shabby blue dress.");
   
   SetRace("nymph");
   SetClass("rogue");
   SetLevel(10);
   RemoveLanguage("Nymal");
   SetLanguage("Sprith", 100, 1);
   SetGender("female");
   SetMorality(-100);
   SetAction(5, ({
     "!speak would you like to buy a flower for someone special?",
      "!emote flashes a brilliant smile.",
   }) );
    SetLocalCurrency("rupies");
   SetMenuItems( ([
        "daisy" : BAZAAR_OBJ "daisy",
        "bouquet of peonies" : BAZAAR_OBJ "peony",
        "pair of tulips" : BAZAAR_OBJ "tulip",
   ]) );
}
