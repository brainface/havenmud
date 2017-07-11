#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("a hallway");
   SetLong("Beams cross overhead, holding up the solid gray stones "
           "which make up the surrounding castle.  Walls surround in "
           "all directions, except to the north and east; the hall "
           "continues to the north, and to the east opens up into "
           "a stairway.  A door, not too large and grand, but not "
           "dingy either, is in the western wall.");
   SetItems( ([
                ({ "eastern stairway","stairway","stairs","stair",
                   "staircase" }) :
                   "To the east, a stairway descends to the first floor "
                   "of the castle.",
                ({ "hall","hallway","way","castle" }) :
                   (: GetLong :),
                ({ "crossing beams","beams","beam","solid gray stone",
                   "solid gray stones","stone","stones","solid stone",
                   "solid stones","gray stones","gray stone","walls",
                   "wall","western wall" }) :
                   "The stones are uniform, mainly the same shape and "
                   "size, and the beams are all identical except in "
                   "placement.  The walls surrounding this hallway "
                   "are very sturdy and seem as if it would take a lot "
                   "to knock them down.  There is a door in the western "
                   "one.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/hall4",
                "east" :  VC_ROOM + "/stair2",
                "west" :  VC_ROOM + "/guest2",
           ]) );
   SetInventory( ([
                    VC_NPC + "/servant" : 1,
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
