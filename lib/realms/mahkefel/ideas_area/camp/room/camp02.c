/* An arctic expedition at the north pole
 *
 * storage corner
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("arctic");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a disorderly corner of the camp");
  SetLong(
    "It appears this corner of the camp has been set aside for storage. "
    "Barrel after barrel, possibly retrieved from the longship's hold, "
    "sit stacked here slowly oozing some fatty material. Broken timbers "
    "and planks lie strewn about between the ruined ship and ice wall, "
    "and scattered weapons and tools are being slowly covered by the "
    "endless drifts of snow."
  );

  SetListen( ([
    "default" : "Terrible waves rythmically crash against the ice wall.",
  ]) );

  SetSmell( ([
    "default" : "So that's what barrels full of whale fat smell like.",
  ]) );

  SetItems( ([
    ({"longship", "wall"}) : "The huge wall of ice and snow looks to have "
      "been built snug to the stern of the ruined ship, forming a rather "
      "impressive, if makeshift, barrier.",
    ({"barrels","barrel", "cask", "casks"}) : "The wooden casks appear to be oozing whale fat, "
      "which has now frozen and effectively glued the barrels together into "
      "one mass.",
    ({"weapons","tools"}) : "Scattered spears, axes, knives, longswords and "
      "gods know what else are half-buried in the snow. Whoever is organizing "
      "things is fighting a losing battle with the arctic conditions.",
    ({"planks","timbers"}) : "Loose wood is piled here haphazardly in a "
      "token gesture of organization.",
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "north" : CAMP_ROOM "camp01",
    "east" : CAMP_ROOM "camp21",
    "northeast" : CAMP_ROOM "camp11",
  ]) );

}

