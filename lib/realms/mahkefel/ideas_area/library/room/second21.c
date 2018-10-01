/* Arcanith Library second11
*                           
* bookfire                  
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
  SetShort("a raging fire");
  SetLong(
    "A raging fire consumes this area."  
  );

  SetListen( ([ 
    "default" : "Flames roar in your ear.",
  ]) );

  SetSmell( ([
    "default" : "The air is thick with ash.",
  ]) );

  SetTouch( ([
    "default" : "%^BOLD%^ORANGE%^The intense heat sears you.%^RESET%^",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "ink_mephit" : random(3),
  ]) );

  SetExits( ([
    "north" : "second20",
    "south" : "second22",
    "west" : "second11",
  ]) );

}

