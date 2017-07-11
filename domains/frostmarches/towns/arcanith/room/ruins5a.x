/*  The eastern road and the barracks enterance.  */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;
 
static void create() {
  room::create();
  SetShort ("road along eastern wall");
  SetClimate("temperate");
  
  SetNightLight(30);
  SetExits( ([
    "west"  : ROOM "/ruins5",
  ]) );

  SetDayLong("The road ends to the east in a pile of rubble.  A large "
             "building lies to the north.  It looks very secure and "
             "may have been a barracks at one time.  The wall is decaying "
             "badly in this area.  Weeds cover the ground and break up the "
             "road.");

  SetNightLong("Light from the wall reviels that the road ends to the east "
                "in a pile of rubble.  A building to the north looks like "
                "it may have been a barracks at one time.  Weeds cover the "
                "ground in a thick carpet.");

  SetItems( ([
    ({ "east end of the road", "east end", "end of the road", "road" })  :
       "The road leads to the east and west.  The east end, however, is "
       "covered by a large amount of debris from the decaying wall.",
    ({ "large amount of debris", "amount of debris", "debris",
       "pile of rubble", "rubble" })  :
       "The east end of the road is covered by a pile of rubble.  The rubble "
       "looks like it may have come from the city wall.  There is no way "
       "around the debris.",
    ({ "building to the north", "large building", "building", "barracks" })  :
       "A large building lies to the north of the road.  It's defensable "
       "location and structure makes it look like a barracks.",
    ({ "white marble wall", "marble wall", "city wall", "wall" })  :
       "The white marble wall gives off a silvery radiance from runes "
       "inscribed on its surface.",
    ({ "silvery radiance", "light from the wall", "silver light", "light" }) :
       "A silver light radiates from the city wall.  The light is strongest "
       "around the runes on the wall.",
    ({ "runes on the wall", "spidery runes", "runes of magic", "runes" })  :
       "Spidery runes cover the marble wall and glow with a silver light.  "
       "The runes of magic cover most of the wall.",
  ]) );

  SetEnters( ([
    "barracks"  : ROOM "/barracks",
  ]) );

  SetListen( ([
    "default"  : "A faint moan comes from the large building.",
  ]) );

   SetInventory( ([
      NPC "/giant_snake" : 1,
   ]) );
}
