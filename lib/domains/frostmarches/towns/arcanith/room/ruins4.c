/* North-South road */
// Mahkefel 2010: removed the mule from inventory,
//  trader now spawns it directly so it will follow.

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("road in the ruins");
  SetClimate("temperate");
  
  SetNightLight(15);
  SetExits( ([
    "north" : ROOM "/ruins6",
    "south" : ROOM "/ruins2",
  ]) );

  SetDayLong("The road continues to lead into the ruins.  Two buildings line "
             "the road.  The first has crumbled and has little substance.  The "
             "second building is taller and is still in decent condition.  "
             "A set of stairs leads up to the next tier of the city to the "
             "north. There is a pale blue glow to the north.");
  SetNightLong("The road continues into the ruins.  Two shadowed buildings "
               "lie on either side of the road.  The first has "
               "decayed into little more than a pile of rubble.  The second "
               "on the other hand, looks to be in relatively good shape.  "
               "A set of stairs leads from this tier of the city to the "
               "next to the north.  A pale blue light illuminates the area "
               "to the north.");

  SetItems( ([
    ({ "single story building", "ruined building", "store", "building" })  :
       "This used to be a single story building at one time.  Now its only "
       "a storefront and a pile of rubble.  There is a sign of a shovel and "
       "rope over the remains of the door.",
    ({ "storefront" })  :
       "Only the front of the ruined building remains standing.",
    ({ "large two story building", "large building", "two story building",
       "tall building", "inn", "building" })  :
       "This is a large two story building that remains in good condition.  "
       "There is a sign of a sleeping man above the door.",
    ({ "road" })  :
       "This road runs to the north and south.  At the north, a set of "
       "stairs leads up to the next level of the city.  A pale blue glow "
       "illuminates the area at the top of the stairs.",
    ({ "stairs" })  :
       "A set of stairs leads from this level of the city to the next.",
    ({ "level of the city", "city" })  :
       "This level of the city sit lower than the one above it.  A blue "
       "light illuminates the area at the top of the stairs.",
    ({ "pale blue light", "blue light", "pale ight", "light" })  :
       "A pale blue light illuminates an area to the north.",
    ({ "area to the north", "area at the top of the stairs", 
       "top of the stairs", "area" })   :
       "The area at the top of the stairs rises above this one.  A blue light "
       "comes from above.",
  ]) );

  SetEnters( ([
    "inn" : ROOM "/inn",
  ]) );

  SetSmell( ([
    "default"  : "The air smells of decay and faintly of flowers.",
  ]) );

  SetListen( ([
    "default"  : "There is little sound here.  A faint trickle of water can "
                 "be heard from the north.",
  ]) );

  SetInventory( ([
     NPC "/koboldm" : 1,
     NPC "/trader"  : 1,
     NPC "/mule"    : 1,
     NPC "/banker"  : 1,
  ]) );
}
