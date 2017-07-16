#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("A bit of the cliff is nearby, off to the northeast, and "
           "it curves to the east and north around that corner.  "
           "Trees grow everywhere else, but allow travel to the north, "
           "south, east, and west.  A path cuts through here and heads "
           "to the north and east, but it is weakly made and very faint.  "
           "A large clump of ferns grows around the trail as it "
           "heads north.");
   SetItems( ([
                ({ "large clump of ferns","large clump","clump",
                   "clump of ferns","fern","ferns","leaves","leaf",
                   "patten","tiny details","tiny detail","details",
                   "detail","full fern","replicas","exact replicas",
                   "replica","exact replica" }) :
                   "The ferns rustle slightly as a tiny breeze hits "
                   "them.  They are all the same green color, and "
                   "the leaves of the fern seem to be exact replicas "
                   "of the full fern; each of the leaves splitting off "
                   "of those follow the same pattern as well, going down "
                   "towards tiny details.",
                ({ "faint path","path" }) :
                   "The faint path leads to the north and east, "
                   "wandering around trees to get to its destinations.", 
                ({ "inside a valley","valley","cliff" }) :
                    (: GetLong :),
                ({ "leafy trees","leafy tree","tree","trees",
                   "leaves","leaf","branches","branch" }) :
                   "Leaves cling to the branches of the trees, "
                   "hanging in their own precarious way as they "
                   "point towards the ground and try to fall.",
                ({ "dirt ground","ground" }) :
                   "The ground is damp and very rich, and some "
                   "leaves have fallen to it.",
           ]) );
   SetObviousExits("north, east, south, west");
   SetExits( ([
                "north" : JD_ROOM + "/valley_5",
                "east"  : JD_ROOM + "/valley_3",
                "south" : JD_ROOM + "/cliff_bottom",
                "west"  : JD_ROOM + "/valley_1",
           ]) );
   SetInventory( ([
                    JD_NPC + "/centipede" : 2,
                    JD_NPC + "/beetle_dung" : 3,
               ]) );
}
