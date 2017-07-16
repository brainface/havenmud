#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an ice-coated cave");
  SetLong("Coated by crystalline ice, the entering light bathes the cave "
    "in a radiance of color.  Rainbows reflect off of the ice, magnifying "
    "the beauty of the room a hundredfold.  The only mar of the perfection "
    "in the room is the messy lair to the east.");
  SetObviousExits("southwest, east");
  SetItems( ([ ({ "crystalline ice", "ice", "walls", "wall"}):
    "Coating every inch of the cave, ice has crystallized on the walls.",
    ({ "ice-coated cave", "cave", "room" }) : (: GetLong() :),
    ({ "messy lair to the east", "messy lair", "lair", "mess",
    "mar", "only mar" }) :
    "The messy lair to the east intrudes upon the "
    "perfection of the light display.",
    ({ "entering light display", "light", "color", "rainbow", "rainbows", 
      "beauty", "perfection", "entering light", "light display", "display", 
      "color"}):
    "The perfection of the light display is almost complete, "
    "interrupted only by the messy lair to the east.",
    ]) );
SetClimate("underground");
  SetExits( ([ "southwest" : ICE_ROOM + "/room3.c",
    "east" : ICE_ROOM + "/elemlair.c"]) );
}


/* Approved by Balishae on Sat Oct  4 23:15:54 1997. */
