/* Arcanith Library first11
 *
 * Foyer. Nothing interesting
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

static void create() {
  // get it started   
  ::create();     

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("an old foyer");           
  SetLong(
    "The library extends in all directions."
  );                                                                          

  SetListen( ([
    "default" : "The floorboards settle and creak.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "north" : ARC_LIBRARY_ROOM "first10",
    "east"  : ARC_LIBRARY_ROOM "first21",
    "south" : ARC_LIBRARY_ROOM "first12",
    "west"  : ARC_LIBRARY_ROOM "first01",
  ]) );

  SetDoor("south", ARC_LIBRARY_OBJ "door_courtyard");
}

