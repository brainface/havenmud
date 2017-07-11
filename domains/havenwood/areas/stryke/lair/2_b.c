#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a tunnel underground");
  SetObviousExits("west, southeast");
  SetExits( ([
     "west" : STRYKE_LAIR + "2_a",
     "southeast" : STRYKE_LAIR + "2_f",
     ]) );
  SetLong("This is a dull and earthy part of the tunnel.  To the southeast, "
          "the tunnel continues down into the earth, while to the west it "
          "seems to head toward the surface.");
  SetSmell( ([
     "default" : "There is a faint odor of smoke here.",
     ]) );
  SetListen( ([
      "default" : "There is almost no noise here at all.",
       ]) );
  }
