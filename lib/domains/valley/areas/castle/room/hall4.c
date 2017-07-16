#include <lib.h>
inherit LIB_ROOM;
#include "../castle.h"

static void create() {
   room::create();
   SetClimate("indoors");
   SetAmbientLight(30);
   SetShort("a hallway");
   SetLong("Walls surround in all directions, except to the south; the "
           "hall continues in that direction.  Beams cross overhead, "
           "holding up the solid gray stones which make up the "
           "surrounding castle.  Doors fit in each of the walls, to the "
           "north, east, and west.  The ones to the north seem rather "
           "grand.");
   SetItems( ([
                ({ "hall","hallway","way","castle" }) :
                   (: GetLong :),
                ({ "crossing beams","beams","beam","solid gray stone",
                   "solid gray stones","stone","stones","solid stone",
                   "solid stones","gray stones","gray stone","walls",
                   "wall"}) :
                   "The stones are uniform, mainly the same shape and "
                   "size, and the beams are all identical except in "
                   "placement.  The walls surrounding this hallway "
                   "are very sturdy and seem as if it would take a lot "
                   "to knock them down.  There are doors in each wall.",
           ]) );
   SetExits( ([
                "north" : VC_ROOM + "/llroom2",
                "east" :  VC_ROOM + "/guest1",
                "west" :  VC_ROOM + "/hall5",
                "south" : VC_ROOM + "/hall3",
           ]) );
   SetInventory( ([
                    VC_NPC + "/soldier" : 2+random(2),
               ]) );
}
