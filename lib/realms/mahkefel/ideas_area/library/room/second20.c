/* Arcanith Library second11
 *                          
 * viewing room             
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
  SetShort("a viewing room");
  SetLong(
    "Like, glass globes or something. Maybe you can spy on players "
    "in this room, Iunno."
  );

  SetListen( ([
    "default" : "You hear a roaring sound to the south.",
  ]) );

  SetSmell( ([
    "default" : "The air is thick with ash.",
  ]) );

  SetInventory( ([
    ARC_LIBRARY_NPC "fire_mephit" : random(3)+1,
    ARC_LIBRARY_NPC "ink_mephit" : random(3),
  ]) );

  SetExits( ([
    "south" : "second21",
    "west" : "second10",
  ]) );

}

