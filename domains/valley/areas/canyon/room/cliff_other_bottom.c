#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("canyon dead-end");
   SetDomain("Valley");
   SetLong("The canyon ends here against a cliff that seems to slope "
           "more gently than the others, and it looks like it would be "
           "possible to climb up to a ledge about halfway to the top "
           "of the cliff walls.  To the southeast is the rest of the "
           "canyon, while the ledge above looks green and welcoming.");
   SetItems( ([
                ({ "canyon dead-end","canyon","dead-end","end",
                   "cliff","cliff walls","cliff wall","wall","walls" }) :
                   (: GetLong :),
                ({ "green ledge","ledge" }) :
                   "The ledge perches about halfway up the canyon "
                   "on the north side, and looks like it could be climbed "
                   "up to.",
           ]) );
   SetObviousExits("up, southeast");
   SetExits( ([
                "up"        : JD_ROOM + "/cliff_other_top",
                "southeast" : JD_ROOM + "/canyon_3",
           ]) );
   SetInventory( ([
                    JD_NPC + "/chameleon" : 4,
                    JD_NPC + "/butterfly" : 2,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:21:15 1998. */
