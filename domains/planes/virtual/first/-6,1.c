/*  Lamrani Temple */
#include <lib.h>
#include "../../planes.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetProperty("no weather", 1);
  SetProperty("lower plane", 1);
  SetShort("outside a large temple");
  SetLong("The ground is an ugly shade of grey here, leading up to "
          "the steps of a large, black temple. Farther to the east, "
          "a huge castle reaches into the sky like a giant finger, "
          "daring any gods to step into its domain and challenge it "
          "in the lower planes. The ground is covered in the same ugly "
          "grey grass, which matches the ground so much as to be barely "
          "noticable, but the grass appears almost tended.");
  SetItems( ([
    ({ "castle" }) : "The castle at the heart of the first plane "
                     "rises to the east.",
    ({ "temple" }) : "The temple is dark black, with symbols of death "
                     "inscribed on it.",
    ({ "symbols", "symbol" }) : "The symbols are a tribute to a long-dead "
                                "god.",
    ({ "grass", "ground" }) : "The grass covers the ground almost fully.",
    ({ "step", "steps" }) : "The steps are carved marble and lead to "
                           "the temple.",
    ]) );
  SetItemAdjectives( ([
     "temple" : ({ "large", "black" }),
     "castle" : ({ "huge" }),
    "grass" : ({ "ugly", "grey" }),
    ]) );
  SetExits( ([
    "north"  : FIRST_PLANE "-6,2",
    "south"  : FIRST_PLANE "-6,0",
    "east" : FIRST_PLANE "-5,1",
    "west" : FIRST_PLANE "-7,1",
    "southeast" : FIRST_PLANE "-5,0",
    "southwest" : FIRST_PLANE "-7,0",
    "northeast" : FIRST_PLANE "-5,2",
    "northwest" : FIRST_PLANE "-7,2",
  ]) );
  SetSmell( ([
    "default" : "The smell of burning incense is intense here.",
    ]) );
   SetListen( ([
    "default" : "The sound of chanting comes from inside the temple.",
    ]) );
  SetEnters( ([
    "temple" : "/domains/planes/temple/room/entrance",
    ]) );
 }
