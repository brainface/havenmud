
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("southeast, down");
  SetShort("at a slope in a cave");
  SetLong(
          "The cave tunnels lead to a slope in the ground. "
          "It reaches deeper into the bowels of this cave "
          "to a lower level. The walls round around this section "
          "of the cave bend leaving only the two obvious passages.");
  SetInventory(([ TOWER_NPC "mummy" : 1 ]));
  SetExits( ([
            "southeast"     : TOWER_ROOMS "cave09",
            "down"          : TOWER_ROOMS "cave12",
           ]) );
  SetSmell( ([
            "default" : "A stong smell of sulfur lingers.",
           ]) );
  SetListen( ([
            "default" : "A howling wind is heard from the slope."
           ]) );
  
  SetItems( ([
     "ceiling" : "The ceiling cones down to form the cave walls and "
                 "runs down with the slope to the west leading down.",
     "walls"   : "They have a much smoother appeal to them, almost "
                 "like man made walls. The ridges almost dissappear.",
     "slope"   : "It trails downward composed of the hard black clay "
                 "that lines the cave floor.", 
     "wall"    : "Made of natual rock, it rounds from the floor and "
                 "reaches to the ceiling.",
    ({ "ground", "floor" }) : "It is made of a dark packed clay and "
                               "lines the cavern ground. The ground "
                               "has been smoothed out making a more "
                               "sturdy platform.",
     "clay" :  "Dark padded black clay makes the ground here and "
	           "leads downward through the slope.",
   ]) );
  SetItemAdjectives( ([
    "clay" : ({ "dark","padded","black" }),
    "slope" : ({ "downward","","" }),
    "wall" : ({ "rock" }),
  ]) ); 
 }
