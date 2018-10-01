/* Arcanith Library first11
 *
 * stairway to second level
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
  SetShort("a rickety staircase");           
  SetLong(
    "An old stairwell. Impassible rubble lies to the north. "
    "A door stands on the southern wall."
  );                                                                          

  SetListen( ([
    "default" : "The floorboards settle and creak.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(3),
  ]) );

  SetExits( ([
    "east" : "first11",
    "south" : "first02",
    "up" : "second01",
  ]) );

  SetDoor("south",ARC_LIBRARY_OBJ "door_janitor");

}

