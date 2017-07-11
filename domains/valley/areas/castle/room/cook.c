#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("cookhouse");
   SetLong("Cramped is the atmosphere of the cookhouse of this castle:  "
           "Everything is scrunched together as close as they can be "
           "while still allowing access.  Dirt has been tramped into "
           "the ground, worn in with no hope of ever being cleaned off "
           "again.  The open doorway to the south is the only respite.");
   SetItems( ([
                ({ "plain rectangular opening","opening","plain opening",
                   "rectangular opening","southern opening",
                }) :
                   "The plain rectangular opening to the south is "
                   "the exit from this room.",
                ({ "cookhouse","house","castle","everything","area" }) :
                   (: GetLong :),
                ({ "tramped in dirt","dirt","ground","floor" }) :
                   "Most floors have some dirt ingrained into them, but "
                   "in this room it has been taken to excess:  It "
                   "has become the overbearing charectoristic of this "
                   "one.",
           ]) );
   SetListen( ([
                 "default" : "Bustling noises come from the area.",
            ]) );
   SetSmell( ([
                "default" : "A generally overbearing smell covers up "
                  "much of the pleasant odor of food preparation:  "
                  "Sweat and heat fills the area.",
           ]) );
   SetExits( ([
                "south" : VC_ROOM + "/gen_01",
           ]) );
   SetInventory( ([
                    VC_NPC + "/cook" : 1,
                    VC_NPC + "/slave_ck" : 2+random(3),
                    VC_NPC + "/mindless" : 1,
               ]) );
}
