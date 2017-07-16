#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"

static void create() {
   sentient::create();
   SetKeyName("nameless slave");
   SetShort("a nameless slave");
   SetId( ({ "slave","human" }) );
   SetAdjectives( ({ "nameless" }) );
   SetLong("No notable features decorate the slave's face or body.  "
           "He moves about with a directness, not caring about the "
           "surrounding world, only to complete the day's work.  This "
           "single-minded attitude has given the slave a listless "
           "movement, but strength and fearless courage--or perhaps "
           "that is stupidit--that would cause him to charge "
           "into anything, so long as he was ordered to by the proper "
           "superiors.");
   SetGender("male");
   SetRace("human");
   SetClass("rogue");
   SetLevel(18+random(2));
   
   SetInventory( ([
                    VC_OBJ + "/pants_br" : "wear pants",
                    VC_OBJ + "/shirt_wh" : "wear shirt",
                    VC_OBJ + "/glove_s" : "wear glove on right hand",
                    VC_OBJ + "/glove_s" : "wear glove on right hand",
               ]) );
   SetLimit(3); 
   SetWander(17);
   SetMorality(180+random(6));
}