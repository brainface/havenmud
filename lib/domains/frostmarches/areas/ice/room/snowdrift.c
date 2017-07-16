#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a snowdrift");
  SetLong("The normal path through the snow has vanished "
    "here, covered by the collapsing snow.  Holes are scattered "
    "in a version of a trail, perhaps where something or "
    "someone has fallen through the snow.");
  SetObviousExits("west, south");
  SetItems( ([ ({ "normal path", "covered path", "path" }):
    "The path has been covered by the collapsing snow.",
    ({ "collapsing snow", "snow" }):
    "Perhaps caused by a large noise, the snow has collapsed "
    "onto the normal path.",
    ({ "scattered holes", "holes", "trail"}):
    "Holes are scattered around in the snow, in a trail of some "
    "sorts."]) );
  SetExits( ([ "west" : ICE_ROOM + "/mageroom.c",
    "south": ICE_ROOM + "/icelake.c"]) );
  SetInventory( ([
       ICE_NPC + "/iceminstrel" :1,
      ]) );
}


/* Approved by Balishae on Sat Oct  4 22:58:44 1997. */
