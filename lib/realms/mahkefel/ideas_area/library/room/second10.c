/* Arcanith Library second11
*                           
* floorless room                  
*                                 
*                                 
*/                                
#include <lib.h>                  

#include "../arc_library.h"

inherit LIB_ROOM;


static void create() {
  // get it started     
  ::create();            

  SetClimate("indoors");
  SetAmbientLight(30);  
  // I hope this is dark?
  SetShort("a collapsed floor");
  SetLong(
    "Goddammit I lost the long."
    "This room has no floor. onenters of surounding rooms will "
    "refuse to let you enter, heartbeat will drop you. ROom checks "
    "for wings/lamrani. There will be a hidden spell here."
  );

  SetListen( ([
    "default" : "Wind or something outside.",
  ]) );

  SetSmell( ([
    "default" : "Bookish.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3),
    ARC_LIBRARY_NPC "ink_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "east" : "second20",
    "south" : "second11",
    "west" : "second00",
  ]) );

}

