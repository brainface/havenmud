#include <lib.h>
#include "../camp.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("inside the black tent");
  SetExits( ([
       "out" : CAMP_ROOM + "cl3",
       ]) );
  SetObviousExits("out");
  SetLong("The light form outside is dulled here, due to the coloring "
          "of the tent's walls.  On one side of the tent hangs an idol "
          "to Taigis, the Elven Lord of Chaos, which excudes a negative "
          "aura around the room.  The tent is obviously the home of a "
          "religious devotee.");
  SetItems( ([
     ({ "idol", "Taigis" }) : "This idol is a small image made into "
                              "the form of Taigis.",
        "incense" : "The incense looks like a small candle.",
       ]) );
  SetSmell( ([
      "default" : "The odor of incense hangs in the air.",
        ]) );
  SetInventory( ([
    CAMP_NPC + "cleric" : 1,
      ]) );
 }
