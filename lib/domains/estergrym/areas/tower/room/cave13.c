
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("west, north");
  SetShort("a sudden turn in the cave");
  SetLong(
          "The cave makes an acute turn to the north with an "
          "abrupt bend. In the corner to the southeast is a chest "
          "which appears to be bolted to the cavern floor. "
          "The ceiling rises with the walls creating a larger "
          "and less encased atmosphere. The ground has some "
          "ridges and maintains a flat surface.");
  SetInventory(([ 
             TOWER_NPC "skeleton3" : 1,
             TOWER_NPC "skeleton2" : 1, 
             TOWER_OBJ "chest" : 1,
             ]));
  SetExits( ([
            "west"     : TOWER_ROOMS "cave12",
            "north"    : TOWER_ROOMS "cave14",
           ]) );
  SetSmell( ([
            "default" : "A soft scent of sulfur is here.",
           ]) );
  SetListen( ([
            "default" : "A slight whistle to the west is heard."
           ]) );
  
  SetItems( ([
     "wall"    : "Made of natual rock, it rounds from the floor and "
                 "reaches to the ceiling.",
	 "turn"    : "The turn bends from the west to the north.",
     "ceiling" : "The ceiling rises slightly upward with the walls. It "
                 "is flat and has few dents, some bends in it. It leads west "
                 "and north leading the tunnel.",
     "walls"   : "The walls border off the east and south with its flat "
                 "surface which rises up to the ceiling and flushes with "
                 "the ground. A chest lies near the south wall facing "
                 "north.",
    ({ "ground", "floor" }) : "The ground has a smooth surface free of "
                              "any debris or dirt. A chest rests on the "
                              "ground bolted near the south section of "
                              "the ground.",
    "bolts"    : "Round iron bolts secure the chest to the cavern ground.",
	"clay" : "Black speckled clay makes the floor which leads on in this "
	         "cave tunnel.",
              ]) );
    SetItemAdjectives( ([
    "wall" : ({ "rock" }),
    "walls" : ({ "rock" }),
    "ground" : ({ "clay" }),
    "floor" : ({ "clay" }),
    "clay" : ({ "black","speckled","dark" }),
  ]) );
  }
