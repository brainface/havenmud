// updated lib chapel 2/june/2017 torak@haven

#include <lib.h>
#include "../parva.h"
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetShort("a shrine to the Drowned God");
  SetExits( ([
    "out" : PARVA_ROOM "wharf1",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong(
    "The walls of this shrine are made of old, graying driftwood, and the "
    "floor is made of equally gray slate tiles. Painted on the driftwood "
    "in muted tones and plaited strands of seaweed are pictograms that "
    "vaguely represent waves, fish, and other creatures of the sea. In the "
    "middle of the shrine stands a flowing altar to the Drowned God."
    );
  SetReligion("Damhair");
  SetInventory( ([
    PARVA_NPC "damhair_cleric" : 1,
    //PARVA_NPC "magic_trainer"  : 1,
    ]) );
}
