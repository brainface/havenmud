#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a forest glade");
  SetLong("Strangely, this area seems unaffected by the "
    "snowstorms raging nearby.  A small campsite is set up, with a "
    "fire roaring away.  A stack of large books sit nearby the fire.");
  SetObviousExits("east, southeast");
  SetItems( ([ ({ "raging snowstorms", "storms", "snow", "snowstorms",
   "raging storms", "raging snowstorm", "storm", "snowstorm" }):
    "Hovering barely out of range, these storms seem to be "
    "frustrated at their inability to blanket the glade with snow.",
    ({ "forest glade", "glade", "snow", "area" }):
    (: GetLong :),
    ({ "small campsite", "campsite", "site", "small site"}):
    "A stack of large books sit next to a roaring fire.  "
    "Whoever set up this camp looks very neat.",
    ({ "stack of large books", "stack", "large books", "stack of books",
    "books", "book", "large book", "magical books", "magical book" }):
    "The books have a definite magical sense to them.",
    ({ "roaring fire", "fire" }):
    "The fire roars away happily, unaware that the snowstorms "
    "nearby should have smothered it by now."]) );
  SetExits( ([ "east" : ICE_ROOM + "/snowdrift.c",
    "southeast": ICE_ROOM + "/icelake.c"]) );
  SetInventory( ([
        ICE_NPC + "/icemage" : 1,
       ]) );
}


/* Approved by Balishae on Sat Oct  4 23:11:44 1997. */
