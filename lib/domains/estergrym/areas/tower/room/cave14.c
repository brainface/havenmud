
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("south, northeast, northwest");
  SetShort("a fork in the tunnel");
  SetLong(
          "The tunnel forks into three separate paths at the "
          "dimly lit sconce. The small section of the "
          "wall the sconce is resting on is made of square slabs "
          "of a dark stone. The ground remains the same displaying "
          "packed black clay and smoothened walls. The ceiling "
          "bends off into a fork lightly glistening in the sparce "
		  "illumination.");
  SetExits( ([
            "south"     : TOWER_ROOMS "cave13",
            "northeast" : TOWER_ROOMS "cave16",
            "northwest" : TOWER_ROOMS "cave15",
           ]) );
  SetInventory(([ 
             TOWER_OBJ "rtorch2" : 1,
             ]));
  SetSmell( ([
            "default" : "Smoke fills the air slightly.",
           ]) );
  SetListen( ([
            "default" : "Wind whistles from the two tunnels.",
           ]) );
  
  SetItems( ([
     "wall"    : "Made of natural rock, it rounds from the floor and "
                 "reaches to the ceiling.",
     "ceiling" : "It follows the three tunnels that turn into the cave. "
                 "It merged into the walls slightly creating these "
                 "triangle shaped tunnels.",
     "walls"   : "The walls have been smoothed and show little dents or "
                 "damage. It bends off into three passages at the torch "
                 "wall.",
     "north wall" : "The north wall holds the rotted sconce "
                    "and is made of a dark rectangle cut stone.",
     "bolt"    : "A single bolt rests in the sconce to attach to the north "
                 "wall.",
     "stone"   : "The stone is made of a shiny black rock and has been "
                 "cut in rectangular shapes to form the north wall.",
     "sconce"  : "The sconce is slightly rusted and fastened to the north "
                 "wall with a bolt.",
    ({ "slabs" }) : "The stone slabs are made of a black "
                                    "stone with a fairly shiny surface. "
                                    "They have been cut in rectangular "
                                    "shapes to form the north wall.",
    ({ "ground", "floor" }) : "The ground has a smooth surface free of "
                              "any debris or dirt. A chest rests on the "
                              "ground bolted near the south section of "
                              "the ground.",
	"clay" : "Dark spotted black clay makes the ground here.",
              ]) );
  SetItemAdjectives( ([
    "sconce" : ({ "rotted","rusty" }),
    "bolt" : ({ "single" }),
    "slabs" : ({ "stone" }),
    "wall" : ({ "rock" }),
 ]) ); 
}