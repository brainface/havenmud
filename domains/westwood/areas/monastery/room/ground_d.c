#include <lib.h>
inherit LIB_ROOM;
#include "../monastery.h"

static void create() {
   room::create();
   SetShort("under a platform");
   
   SetLong("A wooden platform is suspended in the air above, supported "
           "by some dead trees that were chopped in half and levelled "
           "off; because of the time spent making them even, the platfrom "
           "doesn't tilt from side to side or wobble.  Live trees "
           "grow profously to the west and south, blocking travel; it is "
           "possible to go to the east and north, however.  The dirt "
           "is mostly soft, save a circle of earth that is packed hard.");
   SetItems( ([
                ({ "large circle of earth","earth","circle","ground",
                   "dirt","soft dirt","hard dirt","large circle",
                   "circle of earth","depression" }) :
                   "In the soft dirt, a large circle of earth shows in "
                   "a depression.  It looks like it is often trampled on.",
                ({ "live trees","live tree","trees","tree" }) :
                   "Trees who haven't been cut down or bothered with "
                   "grow to the west and south; they are so close "
                   "together that it would be impossible to move "
                   "through them.",
                ({ "wooden platform","platform" }) :
                   "The platform is strong and evenly balanced on the "
                   "support trees.  It look sturdy and it is doubtful "
                   "that it will fall anytime soon.",
                ({ "support trees","support tree","trees","tree",
                   "dead trees","dead tree" }) :
                   "The dead trees were cut in half and then leveled "
                   "off so that they can support the platform evenly.  "
                   "That job was accomplished, and they now just stand "
                   "under the platform, bearing its weight.  The "
                   "trees have yet to decay, either.",
           ]) );
   SetListen( ([
                 "default" : "Wind rustles the trees among the joyous "
                    "noises from above.",
            ]) );
   SetSmell( ([
                "default" : "Forest smells fill the air.",
           ]) );
   SetExits( ([
                "north" : M_ROOM + "ground_a",
                "east"  : M_ROOM + "ground_e",
           ]) );
   SetInventory( ([
                    M_NPC + "knif_tr" : 3+random(3),
                    M_NPC + "knif_da" : 1,
               ]) );
}