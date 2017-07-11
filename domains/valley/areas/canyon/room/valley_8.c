#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("Trees clutter this small area, opening up only to the west.  "
           "To the south, the cliff walls tower high, curving around "
           "to pocket in this small area.  A few trees hang "
           "over the cliff, and a path meanders through some of the trees "
           "and then ends suddenly.");
   SetItems( ([
             ({ "cliff valley","valley","cliff","cliffs","cliff walls",
                "cliff wall","wall","walls","small area","area" }) :
                (: GetLong :),
             ({ "meandering path","path" }) :
                "The path goes off to the west, but doesn't go "
                "anywhere else like most paths would be expected to.  "
                "It disappears towards the south, among some "
                "close growing alder trees.",
             ({ "close growing alder trees","alder tree","close growing "
                "trees","trees","tree","alder trees","close growing "
                "tree","close growing alder tree" }) :
                "The trees are clumped together closely, but it "
                "appears that there is a passage leading into the "
                "cliff!",
             ({ "deciduous trees","tree","trees","deciduous tree" }) :
                "The trees grow all over the area, but there "
                "are some alder trees near the cliff to the south "
                "that look slightly peculiar.",
        ]) );
   SetObviousExits("west");
   SetExits( ([
                "west"  : JD_ROOM + "/valley_7",
                "south" : JD_ROOM + "/cave",
           ]) );
   SetInventory( ([
                    JD_NPC + "/beetle_dung" : 1,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:32:43 1998. */
