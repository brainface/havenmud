/* An arctic expedition at the north pole
 *
 * dog kennel area
 *
 * should really have "the thing" references in here.
 */
#include <lib.h>

// mikes includes dir
#include "../camp.h"

// must be in all rooms
inherit LIB_ROOM;

static void create() {
  // get it started
  ::create();

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("inside a kennel");
  SetLong(
    "A tattered, hair covered sail forms the floor here, surrounded "
    "on all sides by a wooden cage that does little to ward from "
    "the wind. Deep claw marks are etched into the wooden slats "
    "forming the walls, and gouges in the ice show futile attempts "
    "of the hounds to escape their cramped quarters."
  );

  SetListen( ([
    "default" : "Barks and whining fill the air.",
  ]) );

  SetSmell( ([
    "default" : "So that's what frozen dog poo smells like.",
  ]) );

  SetItems( ([
    "kennel" : "A simple wooden fence. Lonely eyes stare back at "
      "you from small gaps in the boards. Some bleeding heart could "
      "probably crawl through the door, were it open.",
    "sleddogs" : "Lonely eyes stare back at "
      "you from small gaps in the boards.",
    "longship" : "The immense shadow of the longship looms over "
      "the tiny kennel.",
    ({"slat","cage","wooden cage","slats"}) : "Planks and slats of various "
      "sizes form this makeshift shelter. They're set just close enough "
      "together to prevent a hound from escaping but do nothing to windbreak.",
    ({"marks","claw marks","gouges","gouge"}) : "Gouges only possible "
      "with days of effort rake into the wood and ice around. Here and there, "
      "frozen blood or broken claws reveal the depth of desperation involved.",
  ]) );

  SetExits( ([
    "out" : CAMP_ROOM "camp00",
  ]) );

  SetInventory( ([
    CAMP_NPC "dog" : random(4)+2,
  ]) );

  SetDoor("out",CAMP_OBJ "kennel_gate");
}

