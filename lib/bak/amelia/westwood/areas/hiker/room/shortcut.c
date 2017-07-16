#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

static void create() {
   room::create();
   SetShort("on a shortcut");
   SetDomain("WestWood");
   SetLong("Skinny branches from trees poke in on the little space left "
           "here, their leaves wet with dew.  Many different plants "
           "cut into the are, damp just as the trees are.  The shortcut "
           "itself is a thin trail of wet earth left over from some "
           "stream that once rushed down through here.  It heads north "
           "and south.");
   SetItems( ([
                ({ "thin shortcut","shortcut","trail" }) :
                   (: GetLong :),
                ({ "damp trees","branch","branches",
                   "leaves","leaf","tree","trees","dew" }) :
                   "The trees are covered with leaves, wet with dew and "
                   "possibly some rainfall.  They grow everywhere, their "
                   "branches filling the area.",
                ({ "different plants","plants",
                   "plant" }) :
                   "Other plants, aside from the trees, flourish closer "
                   "to the ground.  Near their bottoms, dirt has "
                   "caked on but not dried, making it muddy and dirty.",
                ({ "damp earth","earth","ground","mud","dirt" }) :
                   "The ground is wet and damp, having been a river of "
                   "sorts in the past.",
           ]) );
   SetItemAdjectives( ([
                         "shortcut" : ({ "thin" }),
                         "tree" : ({ "damp","skinny" }),
                         "plants" : ({ "different" }),
                         "earth" : ({ "damp","wet" }),
                    ]) );
   SetSmell( ([
                "default" : "The damp earth is fragrant.",
           ]) );
   SetListen( ([
                 "default" : "Lots of noise comes from surrounding "
                    "area.",
            ]) );
   SetExits( ([
                "north" : H_ROOM + "trail_05",
                "south" : H_ROOM + "trail_01",
           ]) );
   SetInventory( ([
                    H_NPC + "babybear" : 1,
               ]) );
}
