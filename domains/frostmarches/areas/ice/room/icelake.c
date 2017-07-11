#include <lib.h>
#include <domains.h>
#include "ice.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an icy lake");
  SetLong("Perfect for skating on, this beautiful lake has been cleared "
    "of the snow.  Frozen solid, it looks like it could support a large load, "
    "but it probably wouldn't be a good idea to experiment.  This area "
    "feels very peaceful.");
  SetItems( ([ ({ "beautiful frozen lake", "frozen beautiful lake", "icy lake",
    "frozen lake", "beautiful lake", "perfect lake", "lake", "ice", "area"}):
    "The frozen lake is very pretty, and lends a peaceful "
    "feel to the area.",
    ({ "snow" }):
    "All the snow has been cleared off of the frozen lake to provide room "
    "to skate in."]) );
  SetExits( ([ "northwest" : ICE_ROOM + "/mageroom.c",
    "north": ICE_ROOM + "/snowdrift.c",
    "southeast" : ICE_ROOM+"/room3",
   "west" :  FROSTMARCHES_AREAS "icefisher/room/campsite",
  ]) );
  SetInventory( ([  ICE_NPC "/nymph.c" : 1 ]) );
}


/* Approved by Balishae on Sat Oct  4 23:13:54 1997. */
