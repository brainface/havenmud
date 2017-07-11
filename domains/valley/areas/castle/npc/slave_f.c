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
           "She moves about with a directness, not caring about the "
           "surrounding world, only for finishing her work.  Something "
           "about her suggests that she lives for commands, hanging "
           "on to the orders she is given and performing them no "
           "matter what the personal consequence, be it exhaustion "
           "or death or anything else.");
   SetGender("female");
   SetRace("human");
   SetClass("rogue");
   SetLevel(15+random(2));
   SetInventory( ([
                    VC_OBJ + "/pants_br" : "wear pants",
                    VC_OBJ + "/shirt_wh" : "wear shirt",
               ]) );
   SetLimit(3); SetWander(18);
   SetMorality(185);
}