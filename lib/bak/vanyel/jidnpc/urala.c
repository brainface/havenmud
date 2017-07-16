//
// Urala the innkeeper
// Created by Zaxan@Haven
//

#include <lib.h>
#include "../jidoor.h"

inherit LIB_BARKEEP;

static void create() {
   barkeep::create();
   SetKeyName("urala");
   SetId( ({ "urala", "barkeep" }) );
   SetShort("Urala the Barkeep");
   SetLong("This little lady is serves the patrons of the War Hall."
           "She seems friendly and willing to help anyone interested "
           "in her services.  She doesn't appear to be much of a "
           "warrior though.");
   SetLevel(5);
   SetRace("sprite");
   SetClass("merchant");
   SetClass("diviner");
   SetGender("female");
   SetMorality(20);
   SetLocalCurrency("rupies");
   SetMenuItems( ([
//      "water" : JID_OBJ "/water",
//      "beer" : JID_OBJ "/beer",
      "steak" : "/std/meal/food/steak",
               ]) );
}
