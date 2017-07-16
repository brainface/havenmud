/*  Lamrani Area */
#include <lib.h>
#include "../../planes.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("no weather", 1);
  SetProperty("lower plane", 1);
  SetShort("near a small temple");
  SetLong("The ground here is little differant than the rest of the "
          "horizon, with a small amount of sickly looking plant life that "
          "appears more dead than alive.  The greyish sky seems to invite "
          "despair with its cold glow. Farther to the east a huge castle "
          "towers over the land like a spire reaching for the heavens. "
          "There is a large shrine to the southeast which appears "
         "to be occupied.");
  SetSmell( ([
     "default" : "The air is sweet with a burning incense.",
    ]) );
  SetListen( ([
      "default" : "There is some form of sound coming from the temple.",
    ]) );
  SetItems( ([
     ({ "castle" }) : "The castle looms in the sky to the east.",
    ({ "sky", "horizon" }) : "The horizon is filled with grey nothing.",
    ({ "temple" }) : "The temple is a black building with odd symbols "
                     "of death and despair on it.",
    ({ "plant life", "life" }) : "The plant life here is nothing more "
                                 "than ragged and dying grass.",
    ({ "grass" }) : "The grass is a hideous shade of grey.",
    ]) );
  SetExits( ([
      "north" : FIRST_PLANE "-7,3",
      "south" : FIRST_PLANE "-7,1",
      "east"  : FIRST_PLANE "-6,2",
      "west"  : FIRST_PLANE "-8,2",
      "southeast" : FIRST_PLANE "-6,1",
    ]) );
 }
