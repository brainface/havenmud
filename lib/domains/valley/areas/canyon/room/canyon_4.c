#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("canyon dead-end");
   SetDomain("Valley");
   SetLong("The canyon comes to an end here, with steep cliff walls "
           "rising high above, and a few scattered trees growing in "
           "the rich soil.  A way leads out to the west, back to "
           "the rest of the canyon.  A small nest hides in the corner.");
   SetItems( ([
                ({ "canyon dead-end","dead-end","end","canyon",
                   "cliff","steep cliff","cliff walls","steep cliff walls",
                   "steep walls","cliff wall","steep cliff wall",
                   "steep wall","wall","walls" }) :
                   (: GetLong :),
                ({ "scattered trees","scattered tree","tree","trees" }) :
                   "The trees flourish in this part of the canyon, "
                   "but the air has a dry quality to it, which is "
                   "probably why there aren't more.",
                ({ "rich soil","soil" }) :
                   "The rich soil is drier here than in other areas "
                   "of the canyon.",
                ({ "small nest","nest","wad","paper","mache",
                   "paper mache" }) :
                   "The nest looks like a wad of paper mache.",
           ]) );
   SetObviousExits("west");
   SetExits( ([
                "west" : JD_ROOM + "/canyon_3",
           ]) );
   SetInventory( ([
                    JD_NPC + "/wasp" : 7+random(4),
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:12:04 1998. */
