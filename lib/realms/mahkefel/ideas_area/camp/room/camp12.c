/* An arctic expedition at the north pole
 *
 * bank igloo
 * (outside)
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
  SetShort("before a torchlit igloo");
  SetLong(
    "An igloo is built into the wall here, and surrounded by a cordon "
    " of torches. The well lit entrance is clear of any snowdrift or "
    "debris present in all other corners of the camp, and tall narrow "
    "windows look out in all directions away from the wall. To the north "
    "smoke from an everburning fire rises, and the pier lies to the "
    "southeast."
  );

  SetListen( ([
    "default" : "This end of the camp is oddly silent.",
  ]) );

  SetSmell( ([
    "default" : "Smoke and ash occasionaly blow in from the north.",
  ]) );

  SetItems( ([
    ({"igloo"}) : "A half hemisphere built into the strong structure of "
      "the ice wall, this igloo looks like it could withstand a small "
      "invasion.",
    ({"wall"}) : "The high ice wall here wards against the occasional "
      "crashing wave of the sea.",
    ({"torches"}) : "Pitch soaked torches are sunk into the ice in a "
      "semicircle around the igloo.",
    ({"windows"}) : "Tall, narrow windows provide a view of the entire "
      "camp.",
    ({"smoke", "fire"}) : "A smoky, smoldering fire burns to the north.",
    ({"pier"}) : "The pier lances into the arctic seas to the southeast.",
    ({"ice","ground","footprints",}) : "The snow here looks swept, "
      "revealing a smooth, semi-transparent ice underfoot."
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "northwest" : CAMP_ROOM "camp01",
    "north" : CAMP_ROOM "camp11",
    "northeast" : CAMP_ROOM "camp21",

    "west" : CAMP_ROOM "camp02",
    "east" : CAMP_ROOM "camp22",    
  ]) );

  SetInventory( ([
   //todo: penguin
  ]) );

  SetEnters( ([
    "igloo" : CAMP_ROOM "igloo_bank",
  ]) );
}

