#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("at the bottom of a cliff");
   SetDomain("Valley");
   SetLong("A path meanders its way up the cliff, finding this place and "
           "heading off to the northeast.  Some trees dangle over the "
           "edge of the cliff, but more grow in this valley, in all "
           "directions.  They do not, however, hamper progress to the "
           "north, northeast, or northwest; all other directions are "
           "blocked by the cliff.");
   SetItems( ([
                ({ "dangling trees","tree","trees","dangling tree",
                   "leaf","leaves" }) :
                   "Leaves hang off the trees, which rustle above "
                   "from precarious positions on the cliff.  "
                   "However, many trees fill the valley as well, "
                   "adding green and life to the area.",
                ({ "bottom of a cliff","bottom of cliff","cliff",
                   "bottom","valley","area" }) :
                   (: GetLong :),
                ({ "steep path","path" }) :
                   "The path wanders about the cliff, searching for the "
                   "easiest possible route down it.  It heads off to "
                   "the northeast from here, but seems fairly scrawny.",
           ]) );
   SetObviousExits("up, northeast, north, northwest");
   SetExits( ([
                "up"        : JD_ROOM + "/cliff_edge",
                "northwest" : JD_ROOM + "/valley_1",
                "north"     : JD_ROOM + "/valley_2",
                "northeast" : JD_ROOM + "/valley_3",
           ]) );
   SetInventory( ([
                    JD_NPC + "/spider_black" : 2,
                    JD_NPC + "/caterpillar" : 3,
               ]) );
}


/* Approved by Zaxan on Sat Jan 17 03:19:58 1998. */
