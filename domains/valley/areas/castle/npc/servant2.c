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
   SetLimit(3); SetWander(25,({ "open east door","go east","close east door",
                   "open north door","north","get coffee from platter",
                   "give first coffee to lady","go south",
                   "close north door","go south","go east","go down",
                   "open west door","go west","go west",
                   "get beer from platter","give first beer to lord",
                   "go east","go north","open north door","go north",
                   "close south door","get coffee from platter",
                   "give first coffee to second diner",
                   "give first coffee to first diner","open west door",
                   "go west","close east door","go south","open trapdoor",
                   "go down","close trapdoor","get beer from platter",
                   "drink first beer","rest","stand up","open trapdoor",
                   "go up","go up" }), 1);
   SetAction(5,({"!put beer in platter","!put coffee in platter"}));
   SetMorality(-125);
}