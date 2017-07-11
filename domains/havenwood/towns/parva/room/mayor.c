#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a comfortable office in Parva");
  SetExits( ([
    "south" : PARVA_ROOM "town_hall",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "mayor" : 1,
    ]) );
  SetLong(
     "This is the office of the Parvan mayor, Admiral Greyjoy. Although a "
     "windowless, plain room, the place has been moderately fixed up with "
     "blue and green rugs to soften the floors, a pair of squashy chintz "
     "chairs, and a desk that looks to have been crafted from an old rudder. "
     "An old, tattered ensign from some long-forgotten ship hangs on the back wall."
     );
  SetItems( ([
    ({ "rug", "rugs" }) : "The blue and green rugs do little to lighten the appearance.",
    ({ "chair", "chairs" }) : "The chairs are cheaply made and appear uncomfortable.",
    "desk" : "The wooden desk appears to have been made from an old rudder.",
    "ensign" : "This ensign appears to be some some long forgotten ship.",
    ]) );
  SetItemAdjectives( ([
    "rug" : ({ "blue", "green", "and" }),
    "chair" : ({ "squashy", "pair", "of" }),
    "ensign" : ({ "old", "tattered" }),
    ]) );
  SetSmell("The mayor's office smells of pipe tobacco.");
}