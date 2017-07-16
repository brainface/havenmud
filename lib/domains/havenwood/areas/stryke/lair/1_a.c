/*  The entrance room of Stryke's lair. */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the mound");
  SetObviousExits("up, east, south");
  SetExits( ([
      "up" : STRYKE_DIR + "connect",
      "south" : STRYKE_LAIR + "1_c",
      "east"  : STRYKE_LAIR + "1_b",
      ]) );
  SetClimate("indoors");
  SetAmbientLight(18);
  SetLong("This dimly lit hole in the ground is a the entrance to a "
          "winding underground tunnel system.  The tunnel continues to "
         "the east, while the south seems to have been carved out as a "
         "lair of some kind.");
  SetSmell( ([
      "default" : "The tunnel has an earthy smell to it.",
      ]) );
  SetListen( ([
       "default" : "The sounds from outside the tunnel can be easily heard.",
      ]) );
  }
