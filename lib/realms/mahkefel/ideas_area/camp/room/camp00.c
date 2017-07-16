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

  SetClimate("arctic");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a dog kennel");
  SetLong(
    "A small kennel, no more than five paces by five paces, houses "
    "a few sleddogs here. Made of sturdy planks that matches rather "
    "uncoincidentally the beached longship, the frozen wall to the north "
    "finishes the enclosure. A door with a simple gravity latch holds "
    "the hounds inside."
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
    ({"plank","planks"}) : "Upon close inspection, the material for "
      "the kennel was obviously ripped from the longship.",
    "wall" : "The wall of frozen snow and ice rises above your field "
      "of vision. A giant would have difficulty touching the top of it.",

  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetExits( ([
    "east" : CAMP_ROOM "camp10",
    "south" : CAMP_ROOM "camp01",
    "southeast" : CAMP_ROOM "camp11",
  ]) );

  SetEnters( ([
    "kennel" : CAMP_ROOM "kennel",
  ]) );

  SetDoor("kennel",CAMP_OBJ "kennel_gate");
}

