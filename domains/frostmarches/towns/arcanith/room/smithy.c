/* Mahkefel jan 2011
 * A smithy trainer area for arcanith
 */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the courtyard of the inn");
  SetClimate("temperate");
  SetAmbientLight(20);
  SetExits( ([
     "east" : ROOM "/inn",
  ]) );

  SetLong(
    "The courtyard is padded with dead grass and surrounded by the "
    "aged walls of the inn. A makeshift forge sits in the center, "
    "exhaling a constant stream of black smoke. A pile of dry logs "
    "sits dangerously close to the open forge and tongs and bellows "
    "are strewn haphazardly across the ground. An open doorway to the "
    "east leads back into the interior of the inn."
  );
  SetItems( ([
    "courtyard" : (: GetLong :),
    ({"grass","ground"}) : "The grass is matted and scorched by smoke and "
      "constant traffic.",
    ({"walls", "inn"}) : "The walls of the inn stand steadfast around the "
      "courtyard, a testament to the engineering skill of the city's "
      "original inhabitants.",
    ({"forge"}) : "Apparently cobbled together from salvaged rubble, the "
      "stone forge looks like it could be used to make very rudimentary "
      "objects like nails and frying pans.",
    ({"logs","pile"}) : "The edges of the logs closest to the forge have "
      "begun to singe and smoke.",
    ({"tongs","bellows"}) : "An assortment of blacksmith tools, apparently "
      "hand-me downs from a previous century, are scattered about the "
      "courtyard.",
    ({"doorway"}) : "The doorway back into the inn is guarded only by a "
      "closed curtain of some sort of animal hide.",
    ({"smoke"}) : "A black column of smoke is seemingly funneled directly "
      "back into the common room of the inn.",
  ]) );

  SetListen( ([
    "default"  : "Fire crackles with glee.",
  ]) );

  SetInventory( ([
    NPC "/blacksmith" : 1,
  ]) );

  SetTouch(
    "%^BOLD%^BLACK%^Hot ash circles around you.%^RESET%^",
  );
}

