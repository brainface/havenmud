/*  The actual lair */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;
int PreExit(string dir);

static void create() {
  room::create();
  SetClimate("indoors");
  SetWarmth(40);
  SetShort("a large cave");
  SetLong("This huge cave is large enough to hold most anything.  The roof "
          "of the cave is nearly forty feet into the sky above you. To the "
          "south the cave opens into a large passage that seems to have "
          "a glitter to it.");
  SetSmell( ([
     "default" : "The rancid smell of death is on the air.",
      ]) );
  SetListen( ([
      "default" : "The cave seems too quiet.",
    ]) );
  SetObviousExits("west, south");
  SetExits( ([
      "west" : STRYKE_LAIR + "2_h",
     ]) );
  AddExit("south", STRYKE_LAIR + "2_j", (: PreExit :) );
  SetInventory( ([
     STRYKE_NPC + "stryke" : 1,
    ]) );
  }

int PreExit(string dir) {
   object dragon;

  if (!(dragon = present("stryke", this_object()))) {
     return 1;
    }
   else {
    dragon->eventForce("emote shifts slightly to block the path.");
    return 0;
   }
  }
