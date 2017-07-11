/*  A section of the tunnel. */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a section of tunnel");
  SetObviousExits("up, east, southeast, south");
  SetExits( ([
      "up" : STRYKE_LAIR + "1_b",
      "east" : STRYKE_LAIR + "2_b",
      "south" : STRYKE_LAIR + "2_d",
      "southeast" : STRYKE_LAIR + "2_c",
     ]) );
  SetLong("This opening in the tunnel system holds a junction of several "
          "passages. To the south, the tunnel continues into the blackness "
          "while to the southeast some small light can be seen. To the east "
          "there is only blackness.");
  SetSmell( ([
     "default" : "The earthy aroma is tinged with smoke from the southeast.",
      ]) );
  SetListen( ([
       "default" : "The crackling of a fire can be heard to the southeast.",
       ]) );
  }
