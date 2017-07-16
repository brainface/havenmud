/* Arcanith Library second11
 *                          
 *study room                
 *                          
 *                          
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
  SetShort("an empty study room");
  SetLong(
    "Overturned tables and chairs line the floor."
  );

  SetListen( ([
    "default" : "You hear a crackling sound from the east.",
  ]) );

  SetSmell( ([
    "default" : "The hair is heavy with dust and ashes.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "ink_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "north" : "second10",
    "east" : "second21",
    "south" : "second12",
    "southwest" : "second02",
    "west" : "second01",
  ]) );

}
