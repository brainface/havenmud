
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("east, up");
  SetShort("the bottom of the slope");
  SetLong(
          "The slope runs along the west wall back up to the "
          "level above. Tucked away along the south wall is "
          "a large pile of black small grained sand. The ground "
          "slopes upward into an above floor of the cave and "
          "also leads east. The walls have leveled out completely "
          "creating an almost flat border.");
  SetInventory( ([
               TOWER_OBJ "bone" : 1,
    			   ]) );
  SetExits( ([
            "east"     : TOWER_ROOMS "cave13",
            "up"       : TOWER_ROOMS "cave11",
           ]) );
  SetSmell( ([
            "default" : "A stong smell of sulfur lingers.",
           ]) );
  SetListen( ([
            "default" : "A howling wind is heard rushing up the slope."
           ]) );
  
  SetItems( ([
     "ceiling" : "Roughly flat it leads to the east. An opening has "
                 "been made to make way for the slope coming down.",
     "walls"   : "They are roughly flat and smooth and made up as the same "
                 "composition and materials as the floor.",
     "slope"   : "It trails upward to another level of the cave.", 
     "wall"    : "Made of natual rock, it rounds from the floor and "
                 "reaches to the ceiling.",
    ({ "ground", "floor" }) : "It is made of a dark packed clay. "
                               "A large pile of black sand rests on "
                               "the ground near the south section of "
                               "the floor.",
    ({ "sand" }) : "The pile consists of a fine "
                   "black powder which makes its "
                   "way up the slope due to the "
                   "heavy draft.",
              ]) );
  SetItemAdjectives( ([
    "sand" : ({ "pile","large","black" }),
    "wall" : ({ "rock" }),
    "walls" : ({ "rock" }),
  ]) ); 
 }
