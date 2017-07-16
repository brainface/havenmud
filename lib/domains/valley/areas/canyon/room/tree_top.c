#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("up a tree");
   SetDomain("Valley");
   SetLong("Green leaves surround one who is up in this tree, "
           "as it is a beautiful deciduous tree with flourishing "
           "life all over it.  Some moss grows on its north side, "
           "and branches poke out all around.  It looks like it "
           "would be fairly easy to climb down from here.");
   SetItems( ([
                ({ "long branches","long branch","branches","branch" }) :
                   "The branches poke out all over the place, but "
                   "only one to the south seems like it might be safe "
                   "to venture out upon.",
                ({ "green leaves","leaves","leaf","green leaf" }) :
                   "The leaves are green and healthy, with little "
                   "withering.",
                ({ "beautiful deciduous tree","tree","beautiful tree",
                   "deciduous tree" }) :
                   (: GetLong :),
                ({ "fuzzy moss","moss","north side","side","little "
                   "trendils","trendils","trendil","little trendil" }) :
                   "Fuzzy moss grows on the nort side of the "
                   "tree, little trendils poking out of it curiously.",
           ]) );
   SetExits( ([
                "south" : JD_ROOM + "/on_limb",
           ]) );
   SetInventory( ([
                    JD_ROOM + "/climb_down_tree" : 1,
                    JD_NPC + "/dryad" : 1,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:25:42 1998. */
