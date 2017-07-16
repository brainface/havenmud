#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   SetDomain("WestWood");
   SetLong("Solidly grounded on tree limbs and supported by many "
           "tree trunks, the platform hangs comfortably in the air "
           "here, well off of the ground.  Some leaves flutter through "
           "the air and land on the platform, falling off in the next "
           "gust of wind.  Rope bridges run to the east and south, " 
           "well supporting to hold people up among the trees.  "
           "A covering roof is attached above this platform, and a "
           "wooden railing encircles it where the rope bridges are "
           "not attached.");
   SetItems( ([
                ({ "covering roof","roof","wood","peak","sides","side" }) :
                   "The roof is in a pyramid shape, with four sides going "
                   "together to a peak in the center above.  It protects "
                   "the platform and those on it from rain and other "
                   "such weather.",
                ({ "wooden railing","railing","wood","rail",
                   "wooden rail" }) :
                   "The railing goes around the entire platform, "
                   "making it much more difficult to fall off.  In fact, "
                   "any sort of fall to the ground would have to be "
                   "intentional because of this rail.  It paused before "
                   "the rope bridges so that people can make it on to "
                   "those safely.",
                ({ "rope bridges","rope","wood","bridges","rope bridge",
                   "bridge","ropes" }) :
                   "Strung between platforms are rope bridges, sturdy "
                   "and well supported by the branches and tree trunks.  "
                   "Rope and wood forms them, and holds them together to "
                   "provide walking space for all the people in the "
                   "area wishing to travel to and from this platform.",
                ({ "wooden platform","platform","wood","wood platform" }) :
                   (: GetLong :),
                ({ "tree limbs","tree limb","limbs","limb","wood",
                   "branches","branch" }) :
                   "The branches are long and strong, stretching out "
                   "between their trunk and others, twining into "
                   "each other and into other trunks.",
                ({ "tree trunks","tree trunk","trunks","trunk","wood" }) :
                   "The branches split off of these tree trunks.  "
                   "All the trunks are solid and go down towards the "
                   "ground below, which can't be seen through all the "
                   "trees.",
                ({ "fluttering leaves","fluttering leaf","leaves",
                   "leaf" }) :
                   "The leaves dance through the air and skitter across "
                   "the platform and catch in the branches and run into "
                   "tree trunks, blown all over by the wind one moment, "
                   "dropping and falling the next, the cycle repeating "
                   "again and again.",
           ]) );
   SetListen( ([
                 "default" : "Merriment echos through the air.",
            ]) );
   SetSmell( ([
                "default" : "Lively smells of a rich world permeate the "
                   "atmosphere.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "plat_b",
                "south" : M_ROOM + "plat_d",
           ]) );
   SetInventory( ([
                    M_NPC + "monk_c" : 2,
                    M_NPC + "monk_j" : 1,
                    M_NPC + "monk_h" : 2+random(2),
                    M_NPC + "trav_wor" : random(2)+1,
                    M_NPC + "musician" : 4+random(3),
               ]) );
}
