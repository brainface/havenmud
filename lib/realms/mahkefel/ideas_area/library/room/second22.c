/* Arcanith Library second22
*                           
* ashes                
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
  SetShort("the charred remains of a library");
  SetLong(
    "Oh no! Fire mephits ate this room."
  );

  SetListen( ([ 
    "default" : "A roaring noise comes from the north.",
  ]) );

  SetSmell( ([
    "default" : "Ashy.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "ink_mephit" : random(3),
    ARC_LIBRARY_NPC "fire_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "north" : "second21",
  ]) );

}

