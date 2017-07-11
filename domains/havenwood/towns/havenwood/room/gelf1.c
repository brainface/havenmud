#include <lib.h>
#include <domains.h>
#include "../wood.h"
inherit LIB_ROOM;

int PreExit() {
  if (this_player()->id("havenwood_wander")) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

static void create() {
  room::create();
  SetShort("in the HavenWood");
  SetExits( ([
     "east"      : HWD_ROOM + "/gelf4",
     "southeast" : HWD_ROOM + "/gelf2",
     "northeast" : HWD_ROOM + "/gelf3",
    ]) );
  AddExit("west", HAVENWOOD_AREAS "wood/rooms/birth", (: PreExit :) );
  SetLong(
    "The Havenwood opens here into a larger area. The trees here are "
    "abnormally large, reaching into the sky as well tended proof that "
    "nature reigns supreme in these woods. The path leading to the east "
    "opens into a large clearing, while paths to the southeast and "
    "northeast head around the edges of the clearing. Off to the west "
    "the path travels deeper into the Havenwood."
    );
  SetItems( ([
    ({ "tree", "trees" }) :
      "The trees here are abnormally large, obviously well tended and "
      "reaching for the sky.",
    ({ "path", "paths" }) :
      "The path head southeast, northeast, west, and east.",
    ]) );
  SetSmell("Clean, fresh forest smells permeate the air.");
  SetListen("Birds chirp happily from the trees.");
  SetInventory( ([
    HWD_NPC "/controller" : 1,
   ]) );
}
