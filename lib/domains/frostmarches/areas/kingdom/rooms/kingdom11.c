
/* A room in the kingdom
   Elasandria 4/13/98
*/
#include <lib.h>
#include "../kingdom.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the queen's chamber");
  SetClimate("indoors");
  SetAmbientLight(45);
  SetLong(
    "The throneroom is resplendant and very feminine. Glowing orbs "
    "hang from spiders threads, setting the room aglow. A silken "
    "carpet of carefully sewn rose petals covers the ground.");
  SetItems( ([
    ({"chamber","room","throneroom"}) : "The room carries the "
      "distinctive marks of a woman.",
    ({"glowing orbs","orbs","orb","light","lights"}) : "These lights "
      "cast a warm light around the room.",
    ({"spiders threads","threads","thread"}) : "These clear threads "
      "occasionally catch and reflect the light from the orbs.",
    ({"silken carpet","carpet","petal","petals","ground"}) : "This "
      "exquisite carpet is made of individual rose petals that were "
      "painstakingly sewn together.",
       ]) );
  SetItemAdjectives( ([
    "glowing orbs" : "warm",
    "spiders threads" : "clear",
    "silken carpet" : "exquisite",
  ]) );
  SetSmell( ([
    "default" : "The essence of roses and femininity wafts faintly "
      "throughout the room.",
  ]) );
  SetListen( ([
    "default" : "The sound of music and laughter can be heard.",
  ]) );
  SetInventory( ([
    KINGDOM_NPC + "queen" : 1,
    KINGDOM_NPC + "attendent" : 2,
    KINGDOM_NPC + "faeriebunny" : 3,
  ]) );
  SetExits( ([
    "east" : KINGDOM_ROOMS + "kingdom12",
  ]) );
}
