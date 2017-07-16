#include <lib.h>
inherit LIB_BARKEEP;
#include "../castle.h"

static void create() {
   barkeep::create();
   SetKeyName("skinny tailor");
   SetShort("a skinny tailor");
   SetId( ({ "tailor" }) );
   SetAdjectives( ({ "skinny" }) );
   SetLong("Knobby elbows stick out of the tailor's skin, and his "
           "bony frame could not hold much strengh to it.  He "
           "looks, however, exceptionally coordinated.");
   SetRace("human");
   SetGender("male");
   SetClass("rogue");
   SetLevel(16);
   SetStat("strength",10,1);
   SetLocalCurrency("nuggets");
   SetMenuItems( ([
                    "belt" : VC_OBJ + "/belt_let",
                    "cloak" : VC_OBJ + "/cloak_be",
                    "long glove" : VC_OBJ + "/glove_l",
                    "working glove" : VC_OBJ + "/glove_s",
                    "pants" : VC_OBJ + "/pants_br",
                    "shirt" : VC_OBJ + "/shirt_wh",
                    "socks" : VC_OBJ + "/socks_l",
                    "vest" : VC_OBJ + "/vest_bl",
               ]) );
   SetCurrency("nuggets", 2 + random(10));
   SetMorality(200);
}
