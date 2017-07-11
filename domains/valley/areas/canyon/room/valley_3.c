#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("against the cliff walls");
   SetDomain("Valley");
   SetLong("The cliff walls have created a small pocket of space for "
           "trees to grow, leaving only the west and southwest open "
           "for travel.  Little breeze strikes this spot, as the "
           "steep cliffs protect this small area.  A path runs through, "
           "heading southwest and west.  Forest debris is scattered "
           "across the ground.");
   SetItems( ([
                ({ "forest debris","debris","sticks","stick",
                   "dirt ground","dirt","ground","twigs","twig",
                   "leaf","leaves" }) :
                   "The dirt ground has sticks and twigs and leaves "
                   "and moss in all sorts of decomposition stages.",
                ({ "cliff walls","cliff wall","wall","walls",
                   "cliff","pocket","space","small pocket",
                   "spot","small area","area","steep cliffs",
                   "steep cliff","cliffs" }) :
                   (: GetLong :),
                ({ "deciduous trees","tree","trees","deciduous tree",
                   "leaves","leaf" }) :
                   "Leaves hang in the trees, dangling from their "
                   "high perches.",
                ({ "faint path","path" }) :
                   "The path is faint and not highly visible, but "
                   "leads west and southwest.",
           ]) );
   SetObviousExits("west, southwest");
   SetExits( ([
                "southwest" : JD_ROOM + "/cliff_bottom",
                "west"      : JD_ROOM + "/valley_2",
           ]) );
   SetInventory( ([
                    JD_NPC + "/slug_garden" : 3,
                    JD_NPC + "/fly_black" : 4,
                    JD_OBJ + "/stick_decomp" : 1,
               ]) );
}
