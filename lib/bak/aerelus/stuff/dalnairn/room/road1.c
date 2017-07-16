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
  SetShort("The Obsidian Road");
  SetLong(
    "The beautifully carved paving slabs along The Obsidian Road glisten, "
    "each infused with shards of the mineraloid for which the road was named. "
    "Short stone walls line either side of the road with flower pots carved "
    "into the stonework, each providing home to radiant bluebells. The road "
    "leads east and west through the city. There is a quaint tavern here, one "
    "of the few buildings along this part of the road that looks welcoming."
  );
  SetItems( ([
  ({ "slabs" }) :
    "The paving slabs along the road have been infused with shards of "
    "obsidian, causing them to glisten in the light.",
  ({ "road" }) : (: GetLong :),
  ({ "obsidian", "mineraloid", "shards" }) : 
    "Obsidian is present almost everywhere here, in the buildings and the "
    "road itself.",
  ({ "walls", "stonework" }) : 
    "The short stone walls which line the road have flower pots carved into "
    "the stonework.",
  ({ "pots" }) :
    "Each of the flower pots are home to bunches of bluebells, which seem "
    "well looked after.",
  ({ "tavern", "inn" }) : 
  	"This welcoming building appears to be a place where one could get drunk "
    "and find something to eat.",
  ({ "buildings" }) : 
    "The buildings here are all made from obsidian. One building, which "
    "appears to be a tavern, looks welcoming.",
  ]) );
  SetItemAdjectives( ([
    "slabs" : ({ "paving" }),
    "road" : ({ "obsidian" }),
    "walls" : ({ "short", "stone" }),
    "pots" : ({ "flower" }),
    "tavern" : ({ "welcoming", "quaint" }),    
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
    "default" : "Merry voices can be heard from the tavern.",
  ]) );
  SetSmell( ([
    "default" : "The smell of beer and warm food drifts from the tavern.",
  ]) );
  SetExits( ([    
    "east" : DAL_ROOM "gates",
    "west" : DAL_ROOM "road2",
  ]) );
  SetEnters( ([
    "tavern" : DAL_ROOM "tavern",
  ]) );
}
