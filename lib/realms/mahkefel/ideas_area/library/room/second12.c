/* Arcanith Library first
 * A balcony (outside)
 * Maybe i'll add a "jump down"
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

static void create() {
  // get it started   
  ::create();     

  SetClimate("temperate");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a rusty iron balcony");           
  SetLong(
    "This balcony hangs over an abandoned courtyard. An empty doorway "
    "leads back to the north."
  );                                                                          

  SetListen( ([
    "default" : "A bird whistles nearby.",
  ]) );

  SetSmell( ([
    "default" : "The moldy scent of stagnant water hangs in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "ink_mephit" : random(3),
  ]) );

  SetExits( ([
    "north" : ARC_LIBRARY_ROOM "second11",
    "down" : ARC_LIBRARY_ROOM "first12",
  ]) );
  
}

