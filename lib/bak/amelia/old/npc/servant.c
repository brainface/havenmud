#include <lib.h>
inherit LIB_SENTIENT;
#include "castle.h"

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
   SetLevel(8+random(2));
   SetClass("valkyr");
   SetInventory( ([
                    VC_OBJ + "/platter" : 1,
                    VC_OBJ + "/beer" : "put beer in platter",
                    VC_OBJ + "/coffee" : "put coffee in platter",
                    VC_OBJ + "/beer" : random(4),
                    VC_OBJ + "/coffee" : random(3),
               ]) );
   SetWander(25,({ "open east door","go east","close west door","go south",
                   "go east","down","open west door","go west","close east"
                   " door","get first beer from platter","give first beer "
                   "to first guest","get first beer from platter","give "
                   "first beer to second guest","go west","get first beer "
                   "from platter","give first beer to lord","go east","go "
                   "north","open west door","go west","go up","open east "
                   "door","go east","close west door","open north door",
                   "go north","close south door","get first coffee from "
                   "platter","give coffee to lady","open south door","go "
                   "south","close north door","open west door","go west",
                   "close east door","go down","open trapdoor","go down",
                   "close trapdoor","sit down","get first beer from "
                   "platter","drink beer","stand up","open trapdoor","go "
                   "up","close trapdoor","go up","go up" }), 1 );
   SetAction(5,({"!put beer in platter","!put coffee in platter"}));
}

