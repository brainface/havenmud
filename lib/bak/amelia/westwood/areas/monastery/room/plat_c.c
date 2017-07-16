#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("on a platform");
   SetDomain("WestWood");
   SetLong("Rope bridges go off the platform to the west and south, "
           "crossing the divide between this platform and other ones.  "
           "On the northwest side of the platform is a building; "
           "it has an open doorway in the middle of it, welcoming "
           "all people inside.");
   SetItems( ([
                ({ "eclatish tavern","tavern","building","doorway",
                   "open doorway","pub" }) :
                   "The building on the northwest side appears to be "
                   "a tavern.  It is not very large, but seems to "
                   "be well-used.",
                ({ "wooden platforms","wooden platform","platform",
                   "platforms","wood" }) :
                   "This platform is not very large, compared to the "
                   "ones to the south and west, while the one to the "
                   "west is apparently the largest of them all.  "
                   "Two rope bridges are connected to this one, going "
                   "south and west to the other platforms.",
                ({ "rope bridges","rope bridge","bridges","bridge",
                   "ropes","rope","wood" }) :
                   "The rope bridges are made of wood along their "
                   "bottoms, providing a sturdy area to walk upon.  "
                   "Ropes make the sides and bind it all together.  "
                   "There are two visible from here, one going to the "
                   "west and the other to the south.",
           ]) );
   SetListen( ([
                 "default" : "Lots of noise eminates from the tavern.",
            ]) );
   SetExits( ([
                "west"  : M_ROOM + "plat_b",
                "south" : M_ROOM + "plat_f",
           ]) );
   SetEnters( ([
                 "tavern" : M_ROOM + "tavern",
            ]) );
   SetInventory( ([
                    M_NPC + "monk_c" : 2,
                    M_NPC + "monk_j" : random(2),
                    M_NPC + "monk_h" : random(3),
                    M_NPC + "trav_wor" : 3+random(3),
               ]) );
}
