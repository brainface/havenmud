/* Arcanith Library second01
 *                          
 * Landing in a staircase   
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
  SetShort("an dusty landing");
  SetLong(
    "This old stairwell continues to another level from here. "
    "The second floor of the library extends to the east. "
    "Heading down the stairwell would lead to the ground floor."
  );

  SetListen( ([
    "default" : "You hear the faint sound of whispers.",
  ]) );

  SetSmell( ([
    "default" : "A sulfurous stench settles from above.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3),
    ARC_LIBRARY_NPC "ink_mephit" : random(3)+1,
  ]) );

  SetExits( ([
    "up" : "third11",
    "east" : "second11",
    "down" : "first01",
  ]) );

}

