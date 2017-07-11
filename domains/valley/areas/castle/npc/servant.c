#include <lib.h>
inherit LIB_SENTIENT;
#include "../castle.h"

static void create() {
   sentient::create();
   SetKeyName("lazy servant");
   SetShort("a lazy servant");
   SetId( ({ "servant" }) );
   SetAdjectives( ({ "lazy" }) );
   SetLong("A yawning look covers the face of the lazy servant as he "
           "tries to make it look as if he is busy and productive.");
   SetGender("male");
   SetRace("dwarf"); 
   SetClass("rogue");
   SetLevel(8+random(2));
   SetInventory( ([
                    VC_OBJ + "/platter" : 1,
                    VC_OBJ + "/beer" : "put beer in platter",
                    VC_OBJ + "/coffee" : "put coffee in platter",
                    VC_OBJ + "/beer" : random(4),
                    VC_OBJ + "/coffee" : random(3),
               ]) );
   SetLimit(3); 
   SetWander(30);
   SetAction(5,({"!put beer in platter","!put coffee in platter"}));
   SetMorality(-125);
}