/* An arctic expedition at the north pole
 *
 * tavern igloo
 *
 *
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
  SetShort("before a noisy igloo");
  SetLong(
    "A noisy, well-trafficked igloo sits here in the snow and ice. "
    "Footprints beat a well-traveled path between it and the fire "
    "nearby to the west, and a wooden statue of a goden woman stands outside the "
    "entrance, holding a jug in her hands. A gate lies to the north, "
    "and the pier runs out through the ocean to the south."
  );

  SetListen( ([
    "default" : "Cursing and drunken songs sing out in a variety of "
      "languages.",
  ]) );

  SetSmell( ([
    "default" : "It smells like vodka even from out here.",
  ]) );

  SetItems( ([
    ({"statue","woman","masthead"}) : "Someone's ripped the spear out "
      "of a longship masthead and nailed a jug into her hands instead. "
      "Her look of determined victory remains, though.",
    ({"ice","ground","footprints","paths",}) : "More snow and ice coats "
      "the ground here, "
      "with deep paths carved out from constant traffic.",
    ({"wall","ice wall"}) : "The ice wall stands giant high to the "
      "east. Torches set along the top provide a low light.",
    ({"igloo","tavern"}) : "The igloo seems large enough to hold an "
      "army, albeit a small one.",
    ({"igloos"}) : "Several igloos surround the fire. The entrance "
      "to a particularly noisy one stands here.",
    ({"gate"}) : "Some sort of gate through the wall lies to the "
      "north",
    ({"pier"}) : "The pier seems to extend almost to the horizon "
      "from here.",
    ({"fire"}) : "A smoky fire burns to the west.",
  ]) );

  SetExits( ([
    "north"     : CAMP_ROOM "camp20",
    "west"      : CAMP_ROOM "camp11",
    "south"     : CAMP_ROOM "camp22",
    "northwest" : CAMP_ROOM "camp10",
    "southwest" : CAMP_ROOM "camp12",
  ]) );

  SetInventory( ([
    CAMP_NPC "guard" : random(2),
  ]) );

  SetEnters( ([
  "igloo" : CAMP_ROOM "igloo_tavern",
  ]) );
}


