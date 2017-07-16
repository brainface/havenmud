/* Arcanith Library
 *                          
 * top of the library
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
  SetShort("a defiled tower room");
  SetLong(
    "Oh no daemon here. "
    "Top of the library. View of surrounding buildings. "
    "Tomes spread everywhere, profane sigils on the walls. "
    "Etc, yadddayadda."
  );

  SetListen( ([
    "default" : "The floorboards groan ominously underneath.",
  ]) );

  SetSmell( ([
    "default" : "It stinks of sulfur.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "mepheus" : 1,
  ]) );

  SetExits( ([
    "down" : "second01",
  ]) );

}

