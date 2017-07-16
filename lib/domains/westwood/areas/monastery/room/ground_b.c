#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("under a platform");
   
   SetLong("Gentle winds stir up the few plants that grow beneath "
           "the large wooden platform that is directly above.  The "
           "dirt here is hard but moist, packed together around the "
           "bottoms of the cut apart trees used to support the "
           "platform.  The world is open to the east, west, and south; "
           "to the north, a wall of trees blocks movement.");
   SetItems( ([
                ({ "support trees","support tree","trees","tree",
                   "dead trees","dead tree","cut apart trees",
                   "cut apart tree","wonderful supports",
                   "wonderful support","supports","support" }) :
                   "The trees exist in two forms around this platform; "
                   "one as live trees to the north, and the other as "
                   "dead trees that have been cut in half and made into "
                   "supports.  The dead ones are still strong and have "
                   "yet to decay; they make wonderful supports.",
                ({ "live trees","live tree","tree","trees","wall of trees",
                   "wall" }) :
                   "Live trees grow so close to the north that "
                   "they have formed a wall blocking passage.",
                ({ "rich dirt","jard dirt","moist dirt","dirt" }) :
                   "The dirt beneath the platform has probably not been "
                   "used for any growing in a long while, so has "
                   "managed to store up many nutrients.  As such, "
                   "some tiny plants have begun to grow in it, "
                   "flourishing even though they lack a lot of sun.  The "
                   "dirt is packed together fairly well under much of "
                   "the platform, and the plants do not grow there.",
                ({ "tiny plants","tiny plant","plants","plant" }) :
                   "The tiny plants have had hardly any time to grow "
                   "in this rich dirt, but they look like they're "
                   "managing, despite the lack of sun that can reach "
                   "them under the platform.",
                ({ "large wooden platform","large platform",
                   "wooden platform","platform","solid fixture",
                   "fixture" }) :
                   "The platform is supported by dead trees and "
                   "other supports, ones that must have been fashioned "
                   "from the upper parts of the trees that have been "
                   "cut apart.  It remains a solid fixture in the sky, "
                   "and it is doubtful that it would fall anytime soon.",
           ]) );
   SetListen( ([
                 "default" : "The soft breeze rustles lightly.",
            ]) );
   SetSmell( ([
                "default" : "The rich earth smells permeate the area.",
           ]) );
   SetExits( ([
                "east"  : M_ROOM + "ground_c",
                "west"  : M_ROOM + "ground_a",
                "south" : M_ROOM + "ground_e",
           ]) );
   SetInventory( ([
                    M_NPC + "pole_usyg" : 1,
                    M_NPC + "pole_tr"   : 3+random(3),
               ]) );
}
