/*  Part of the tunnel */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetLong("The tunnel curves here, leading to the south and to the "
          "northwest.  To the south the tunnel stays about level "
          "with where it is now, while to the northwest it heads toward "
          "the surface.");
  SetSmell( ([
     "default" : "There is a musty earth smell here.",
        ]) );
  SetListen( ([
        "default" : "The tunnel has a faint echo to it.",
      ]) );
  SetShort("a section of tunnel");
  SetObviousExits("northwest, south");
  SetExits( ([
     "northwest" : STRYKE_LAIR + "2_b",
    "south" : STRYKE_LAIR + "2_g",
   ]) );
  }
