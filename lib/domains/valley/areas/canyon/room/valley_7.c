#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("The valley walls are close to the southeast, but "
           "hardly visible in other directions.  Trees cover "
           "much of the area, hiding things in their concealing "
           "branches.  A path meanders across this area to "
           "the southwest and east, and the trees let one through "
           "to the north, east, south, southwest, and west.");
   SetItems( ([
                ({ "concealing trees","tree","trees","concealing tree",
                   "concealing branches","concealing branch","branch",
                   "branches","leaves","leaf" }) :
                   "The trees surround the area, splitting up into "
                   "clumps that allow passage to the east, south, "
                   "southwest, west, and north.  A path heads through "
                   "those trees to the east and southwest.",
                ({ "tiny cocoons","cocoon","cocoons","tiny cocoon" }) :
                   "The cocoons are miniscule is size, looking like "
                   "some young, tender leaf that died in its early "
                   "ages, curling up as it browned and withered.",
                ({ "cliff valley","valley","valley walls","valley wall",
                   "wall","walls","cliff" }) :
                   (: GetLong :),
                ({ "meandering path","path" }) :
                   "The path wanders around the area, picking its "
                   "way around trees.",
           ]) );
   SetSearch( ([
                 "trees" : "Leaves and normal tree-like parts are "
                           "easily visible inside the trees, but "
                           "hidden behind a couple of the leaves are "
                           "tiny cocoons, no large than the tip of "
                           "a blade of grass.",
            ]) );
   SetObviousExits("north, east, south, southwest, west");
   SetExits( ([
                "southwest" : JD_ROOM + "/valley_4",
                "west"      : JD_ROOM + "/valley_6",
                "north"     : JD_ROOM + "/canyon_1",
                "east"      : JD_ROOM + "/valley_8",
                "south"     : JD_ROOM + "/valley_5",
           ]) );
   SetInventory( ([
                    JD_NPC + "/caterpillar" : 1,
                    JD_NPC + "/butterfly" : 2+random(4),
               ]) );
}
