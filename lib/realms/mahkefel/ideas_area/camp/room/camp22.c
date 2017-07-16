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
  SetShort("A gap in the wall");
  SetLong(
    "A small gap in the wall here leads to a makeshift pier to the south. " 
    "Spears driven haft-first into the ground irregularly face away from "
    "the interior of the camp. The smooth piling snow shows evidence of "
    "little traffic. An igloo stands to the west and north, and a huge "
    "bonfire smokes to the northwest."
  );

  SetListen( ([
    "default" : "Frigid waves crash against the creaking pier to the south.",
  ]) );

  SetSmell( ([
    "default" : "Smoke from the fire pools here, clogging your nostrils with ash.",
  ]) );

  SetItems( ([
    ({"ground","snow"}) :
      "You can't see any footprints you haven't left yourself.",
    ({"wall"}) : "A giant-high wall of ice, protecting the camp from... "
      "something?",
    ({"gap"}) : "The gap in the wall is barely wide enough for one human to "
      "squeeze through.",
    ({"spears","spear"}) : "The spears seem to be made to stop a charge from "
      "the pier, and require a bit of slow weaving to go around. Bits of meat "
      "are stuck to some of the spearheads.",
    ({"bits","meat","bits of meat"}) : "Something gorey and burnt. Occasionally "
      "it seems to twitch in the wind.",
    ({"ice"}) : "Ice covers everything here.",
    ({"pier"}) : "The end of the pier is barely visable through a haze of "
      "whirling snow and ice.",
    ({"igloo","igloos"}) : "Makeshift structures of ice. You can't see much "
      "else through the smoke from here.",
    ({"fire","bonfire", "smoke"}) : "A fire burns defiantly to the northwest. "
      "It seems controlled.",
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "north" : CAMP_ROOM "camp21",
    "south" : CAMP_ROOM "pier23",
    "northwest" : CAMP_ROOM "camp11",
    "west" : CAMP_ROOM "camp12",
  ]) );

  SetInventory( ([
   //todo: penguin
  ]) );

}

