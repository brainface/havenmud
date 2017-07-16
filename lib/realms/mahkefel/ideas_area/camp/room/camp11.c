/* An arctic expedition at the north pole
 *
 * central fire
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
  SetShort("a smoking bonfire");
  SetLong(
    "A large circle of rocks has been gathered here, and on top of that "
    "a rather large assortment of charred timber is piled and slowly "
    "smoking from a low fire. Footprints of constant traffic canvas "
    "the area. Igloos face the fire to the north, east, and south, and "
    "to the west the shadow of a large ship looms."
  );

  SetListen( ([
    "default" : "Burning timber bubbles and pops intermittedly.",
  ]) );

  SetSmell( ([
    "default" : "It smells like burnt flesh and cooked meat.",
  ]) );

  SetItems( ([
    ({"circle","rocks"}) : "It looks like the circle of rocks prevents "
      "the fire from simply melting through to wherever the ground is.",
    ({"timber","wood","fire","fat"}) : "The bonfire, a good three paces "
      "in diameter, seems to be composed of timber soaked in whale fat. ",
    ({"ground","footprints"}) : "Booted footprints run about from igloo "
      "to igloo. It appears this warm spot is a popular place.",
    ({"igloo","igloos"}) : "Ice igloos surround the fire.",
    ({"shadow","ship"}) : "A large ship seems to be parked on the ice to "
      "the west.",
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "northwest" : CAMP_ROOM "camp00",
    "north" : CAMP_ROOM "camp10",
    "northeast" : CAMP_ROOM "camp20",

    "east" : CAMP_ROOM "camp21",
    "west" : CAMP_ROOM "camp01",

    "southwest" : CAMP_ROOM "camp02",
    "south" : CAMP_ROOM "camp12",
    "southeast" : CAMP_ROOM "camp22",

  ]) );

  SetInventory( ([
   CAMP_NPC "guard" : random(2)+1, 
  ]) );


}

