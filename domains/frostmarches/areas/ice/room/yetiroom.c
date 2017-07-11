#include <lib.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a living room");
SetClimate("arctic");
  SetLong("Decorated with bits and pieces of previous explorers, this "
    "area of the snow definately looks lived-in.  All the snow has been "
    "pushed out of the way of a large circle, with paths leading south "
    "and east.");
  SetObviousExits("south, east");
  SetItems( ([ ({ "bits and pieces of previous explorers", "explorers",
    "remains", "bits and pieces", "bits", "pieces", "previous explorers" }):
    "These gory remains serve as a warning to any intruders "
    "that the homemaker is not a very nice person.",
    ({ "area", "circle", "large circle", "room", "living room" }):
    (: GetLong :),
    ({ "homemaker", "myth", "myths" }): "It looks like a yeti "
    "lives here.  But aren't those just myths?",
    ({ "snow"}):
    "The snow has been pushed out of the way of a large circle, "
    "with paths leading south and east.",
    ({ "paths", "path", "south", "east" }):
    "The paths in the snow lead south and east."]) );
  SetExits( ([ "east" : ICE_ROOM + "/boneroom.c",
    "south": ICE_ROOM + "/ropebridge.c"]) );
  SetInventory( ([
       ICE_NPC  + "/yeti" : 1,
      ]) );
}


/* Approved by Balishae on Sat Oct  4 22:57:34 1997. */
