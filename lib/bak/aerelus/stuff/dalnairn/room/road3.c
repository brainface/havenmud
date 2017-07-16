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
  SetShort("before the city hall on Obsidian Road");
  SetLong(
    "The beautifully carved paving slabs along The Obsidian Road glisten, "
    "each infused with shards of the mineraloid for which the road was named. "
    "Short stone walls line either side of the road with flower pots carved "
    "into the stonework, each providing home to radiant bluebells. The road "
    "ends here before an obsidian staircase to the west, leading to the "
    "Dalnairn city hall. The barracks, home of the city guard, lie south. "
    "The Obsidian Road leads east to other parts of the city." 
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
  ({ "buildings" }) : 
    "The buildings here are all made from obsidian. To the west lies the "
    "city hall, up an obsidian staircase. The barracks, home of the city "
    "guard, lies to the south.",
  ({ "hall" }) : 
    "The large building up an obsidian staircase just to the west is the "
    "Dalnairn city hall, where all city related business is carried out.",
  ({ "staircase" }) : 
    "The obsidian staircase leads up to the Dalnairn city hall.",
  ({ "barracks" }) : 
    "The barracks lie to the south. Guards come and go regularly as they "
    "change shift.",
  ]) );
  SetItemAdjectives( ([
    "slabs" : ({ "paving" }),
    "road" : ({ "obsidian" }),
    "walls" : ({ "short", "stone" }),
    "pots" : ({ "flower" }),    
    "hall" : ({ "city" }),
    "staircase" : ({ "obsidian" }),
  ]) );
  SetInventory( ([    
  ]) );
  SetListen( ([
    "default" : "The sounds of city life are all around.",
  ]) );
  SetSmell( ([
    "default" : "The refreshing mountain air is pleasant.",
  ]) );
  SetExits( ([    
    "east" : DAL_ROOM "road2",    
  ]) ); 
  SetEnters( ([
    "hall" : DAL_ROOM "hall",
    "barracks" : DAL_ROOM "barracks",
  ]) );
}
