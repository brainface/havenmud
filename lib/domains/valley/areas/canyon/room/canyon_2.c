#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a canyon");
   SetDomain("Valley");
   SetLong("The canyon heads off to the north and southwest as the "
           "cliff walls gain size to the north.  They seem to level "
           "off somewhere to the southwest, but retain their steepness.  "
           "Deciduous trees grow thickly here, growing sparser to the "
           "north.");
   SetItems( ([
                ({ "steep canyon","canyon" }) :
                   (: GetLong :),
                ({ "cliff walls","cliff","cliff wall","wall","walls" }) :
                   "The cliff walls are gray and plain, made of "
                   "a crumbling gray rock.  To the north, the walls "
                   "grow in size, poking out into the sky "
                   "higher and higher, but to the southwest they seem "
                   "shorter.",
                ({ "crumbling gray rock","gray rock","rock",
                   "crumbling rock","edge" }) :
                   "The rock is stacked against itself like a pile "
                   "of papers, and the edge is beginning to smooth "
                   "out and crumble to the ground.",
                ({ "deciduous trees","deciduous tree","tree",
                   "trees" }) :
                   "The trees, enjoying the protective ecosystem "
                   "of the steep canyon, are growing rather "
                   "thickly.  However, they seem to drop off in " 
                   "population to the north.",
           ]) );
   SetObviousExits("north, southwest");
   SetExits( ([
                "north"     : JD_ROOM + "/canyon_3",
                "southwest" : JD_ROOM + "/canyon_1",
           ]) );
   SetInventory( ([
                    JD_NPC + "/hummingbird" : 3,
                    JD_NPC + "/chameleon" : 2,
                    JD_NPC + "/pony_shaggy" : 1,
               ]) );
}
