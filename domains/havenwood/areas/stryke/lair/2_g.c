/*  Part of the tunnel */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetLong("The tunnel continues in several directions from here. "
          "To the northeast there is a slight decline into the darkness, "
          "while to the north the level stays the same.  To the northwest "
          "the tunnel leads back to the surface.");
  SetTouch( ([
     "default" : "There is some heat coming from the northeast.",
      ]) );
  SetListen( ([
      "default" : "A faint breating noise comes from the northeast",
      ]) );
  SetSmell( ([
    "default" : "The smell of death carries from the northeast.",
    ]) );
  SetShort("a section of tunnel");
  SetObviousExits("northwest, north, northeast");
  SetExits( ([
     "northwest" : STRYKE_LAIR + "2_c",
    "north" : STRYKE_LAIR + "2_f",
    "northeast" : STRYKE_LAIR + "2_h",
   ]) );
  }
