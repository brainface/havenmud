/* Arcanith Library second11
*                           
* out on the roof                 
*                           
*                           
*/                          
#include <lib.h>

#include "../arc_library.h"

inherit LIB_ROOM;


static void create() {
  // get it started     
  ::create();            

  SetClimate("temperate");
  // I hope this is dark?
  SetShort("out on the roof");
  SetLong(
    "Out on the roof. It's outdoors! cast natural charge!"
  );

  SetListen( ([ 
    "default" : "Wind whistles provacatively.",
  ]) );

  SetSmell( ([
    "default" : "Bookish.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "ink_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "east" : "second10",
  ]) );

}

