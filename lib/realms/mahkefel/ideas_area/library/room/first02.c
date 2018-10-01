/* Arcanith Library first11
 *
 *oken tab
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
  SetShort("a dusty janitor's closet");           
  SetLong(
    "templong"
  );                                                                          

  SetListen( ([
    "default" : "The floorboards settle and creak.",
  ]) );

  SetSmell( ([
    "default" : "Dust is heavy in the air.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "dust_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "wind_mephit" : random(3),
    ARC_LIBRARY_OBJ "stepladder" : 1,
  ]) );

  // door behavior property
  SetProperty("janitor",1);

  SetExits( ([
    "north" : "first01",
    "east" : "first12",
  ]) );
 
  SetDoor( "north", ARC_LIBRARY_OBJ "door_janitor");
}

