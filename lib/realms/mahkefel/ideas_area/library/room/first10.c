/* Arcanith Library first11
 *
 *oken tab
 */
#include <lib.h>                   

// mikes includes dir
#include "../arc_library.h" 

// must be in all rooms
inherit LIB_ROOM;      

#include "../fly.h"


static void create() {
  // get it started   
  ::create();     

  SetClimate("indoors");
  SetAmbientLight(30); // I hope this is dark?
  SetShort("a heavily damaged room");           
  SetLong(
    "The floor above has completely collapsed into this room. "
    "A mess of rotten support beams and ruined tiles cover the "
    "ground. "
  );                                                                          

  SetListen( ([
    "default" : "The remaining support beams groan with effort.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3),
    ARC_LIBRARY_NPC "wind_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "east" : "first20",
    "south" : "first11",
  ]) );

  AddExit( "up","second10", (:checkFlying:) );

  you_cant_fly = "You see no easy way to reach the bookshelves above.";
}

