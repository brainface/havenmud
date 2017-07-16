/* Arcanith Library second22
*                           
* map room                 
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
  // I hope this is dark?
  SetShort("a musty map room");
  SetLong(
    "There's probably some maps here."
  );

  SetListen( ([ 
    "default" : "A roaring noise comes from the north.",
  ]) );

  SetSmell( ([
    "default" : "Musty.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "ink_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "fire_mephit" : random(3),
  ]) );

  SetExits( ([
    "northeast" : "second11",
  ]) );

}

