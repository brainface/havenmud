/* An arctic expedition at the north pole
 *
 * main gate
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
  SetShort("at the gate to the camp");
  SetLong(
    "A goden-high hole in the wall to the north here is sealed by "
    "a thick wooden "
    "gate. A weapons rack holds several spears nearby, and torches "
    "along the wall provide illumination to the entire area. To the "
    "west and south, two igloos surround a fire."
  );

  SetListen( ([
    "default" : "Cruel winds scream and moan over the wall.",
  ]) );

  SetSmell( ([
    "default" : "It smells like stale and nervous sweat.",
  ]) );

  SetItems( ([
    "wall": "Giant-high and two paces thick, the wall appears to be "
      "made entirely of packed snow and ice. Torches along the top "
      "light the area.",
    "torches" : "Torches along the top of the wall and flanking the "
      "gate illuminate the area.",
    ({"igloos","two igloos","igloo", "fire"}) : "Two or three igloos "
      "surround a fire to the southwest.",
  ]) );

    //"Claw marks along the ground and wall show "
    //"where the hounds have futily attempted to escape their cramped "
    //"quarters.

  SetInventory( ([
    CAMP_NPC "guard"      : random(3)+1,
    CAMP_NPC "dog"        : random(2)+1,
    CAMP_OBJ "weapon_rack": 1,
  ]) );

  SetExits( ([
    "north" : CAMP_ROOM "camp10", //TODO: CHANGE 
    "west" : CAMP_ROOM "camp10",
    "southwest" : CAMP_ROOM "camp11",
    "south" : CAMP_ROOM "camp21",
  ]) );

  SetDoor("north",CAMP_OBJ "camp_gate");
}

