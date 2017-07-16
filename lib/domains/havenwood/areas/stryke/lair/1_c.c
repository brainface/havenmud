/*  A lair of some wolves.  */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(18);
  SetShort("a small lair");
  SetObviousExits("north");
  SetExits( ([
       "north" : STRYKE_LAIR + "1_a",
     ]) );
  SetSmell( ([
     "default" : "The smell of decaying flesh makes this room stink.",
     ]) );
  SetListen( ([
      "default" : "The sounds of the outworld can no longer be heard.",
      ]) );
  SetInventory( ([
       STRYKE_NPC + "wolf" : 1,
      ]) );
  SetLong("This hollowed out portion of the tunnel seems to have been "
          "taken over by some kind of animal as a lair.  The remnants of "
          "different meals and old bones litter the ground.  To the north "
          "the tunnel continues outward.");
  SetItems( ([
       ({ "bone", "bones", "remnant", "remnants", "meal", "meals" }) :
            "These seem to be the leftovers of happily eaten meals.",
     ]) );
  }
