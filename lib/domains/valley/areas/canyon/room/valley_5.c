#include <lib.h>
#include "../jidnewbi.h"
inherit LIB_ROOM;

static void create() {
   room::create();
   SetShort("inside a valley");
   SetDomain("Valley");
   SetLong("The cliff rises to the east, curving around at the southern "
           "and northern sides.  It is unusually steep here, and no "
           "trees have found purchase on its slopes but some dirt "
           "has managed to collect on the cliffs.  Plenty of trees "
           "are growing, healthy and strong, here in the valley.  "
           "Progress can be made to the north, south, and west; a path "
           "goes south and west from here, curving around trees.");
   SetItems( ([
                ({ "cliff dirt","dirt" }) :
                   "The dirt on the cliff seems dry and less rich "
                   "than that the trees are growing in below.",
                ({ "cliff valley","valley","cliff","sides","side",
                   "slopes","slope","northern side","southern side" }) :
                   (: GetLong :),
                ({ "healthy trees","healthy tree","tree","trees" }) :
                   "A path meanders around the bases of the healthy "
                   "trees, which fill the valley with their vibrant "
                   "greens and browns.",
                ({ "curving path","path" }) :
                   "The path goes all about, heading in no particular "
                   "direction, but it mainly goes south and west here.",
           ]) );
   SetObviousExits("north, west, south");
   SetExits( ([
                "north" : JD_ROOM + "/valley_7",
                "west"  : JD_ROOM + "/valley_4",
                "south" : JD_ROOM + "/valley_2",
           ]) );
   SetInventory( ([
                    JD_NPC + "/pony_shaggy" : 2,
                    JD_NPC + "/jay_blue" : 1+random(3),
               ]) );
}
