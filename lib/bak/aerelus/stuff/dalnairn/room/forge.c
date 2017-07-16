// Dalnairn
// Aerelus

#include <lib.h>
#include <domains.h>
#include "../dalnairn.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(30);
  SetClimate("temperate");
  SetShort("in the dalnairn forge");
  SetLong(
    "The Dalnairn forge is perhaps the least attractive building in the city. "
    "The owner takes great pride in his work, which has priority over the "
    "condition of his building. Pieces of junk metal line the floor, waiting "
    "to be hammered into useful objects. A raging furnace, surrounded by "
    "stone, lies behind the owner's desk."
  );
  SetItems( ([
  ({ "forge", "building" }) : (: GetLong :),
  ({ "junk", "metal", "pieces" }) : 
    "These pieces of metal will one day be transformed into useful objects "
    "such as weapons, armour and shields. For now, they line the floor, "
    "creating a mess.",
  ({ "furnace" }) : 
    "The furnace is extremely hot. The owner constructs his weapons here "
    "in the intense heat.",
  ({ "stone" }) : 
    "The stone surrounds the furnace, absorbing most of the heat.",
  ({ "desk", "papers" }) : 
    "The owner's desk is covered with papers, mostly orders for weapons and "
    "armour.",    
  ]) );
  SetItemAdjectives( ([
    "forge" : ({ "dalnairn" }),
    "pieces" : ({ "junk", "metal" }),
    "junk" : ({ "metal" }),
    "metal" : ({ "junk" }),
    "furnace" : ({ "raging" }),    	
  ]) );
  SetInventory( ([ 
    DAL_NPC "drostan" : 1,   
  ]) );
  SetListen( ([
    "default" : "The sound of metal being pounded by a hammer is "
      "overwhelming.",
  ]) );
  SetSmell( ([
    "default" : "The forge smells of smoke from the furnace.",
  ]) );
  SetExits( ([
    "out" : DAL_ROOM "road4",
  ]) );  
}
