/*  Part of the tunnel */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetLong("The tunnel curves here, leading in an arc from the northeast "
          "to the northwest. Along this section of tunnel there is "
          "very little to see except the underground features of "
          "rock and stone.");
  SetSmell( ([
      "default" : "There is a very earthy smell here.",
    ]) );
  SetListen( ([
       "default" : "There is a faint crackling sound coming from the north" 
                   "east.",
    ]) );
  SetShort("a section of tunnel");
  SetObviousExits("northwest, northeast");
  SetExits( ([
     "northwest" : STRYKE_LAIR + "2_d",
    "northeast" : STRYKE_LAIR + "2_c",
   ]) );
  }
