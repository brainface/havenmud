#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("on a ledge");
   SetDomain("Valley");
   SetLong("The ledge is about half-way up to the top of the cliff "
           "walls, but rather broad and has a rich soil as a base "
           "for the plants and flowers growing here.  A way out "
           "is down the cliff; a managable gentle slope exists in that "
           "direction.  The ledge continues to the west.");
   SetItems( ([
                ({ "broad ledge","ledge" }) :
                   (: GetLong :),
                ({ "rich soil","soil","plants","plant","flowers",
                   "flower","pretty flowers","pretty flower" }) :
                   "Plants flourish among some pretty flowers in the "
                   "rich soil here.",
                ({ "gentle slope","slope","cliff","downward slope" }) :
                   "The downward slope leads off the cliff.",
           ]) );
   SetObviousExits("west, down");
   SetExits( ([
                "west" : JD_ROOM + "/tree_bottom",
                "down" : JD_ROOM + "/cliff_other_bottom",
           ]) );
   SetInventory( ([
                    JD_NPC + "/butterfly" : 3,
                    JD_NPC + "/caterpillar" : 4,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:21:49 1998. */
