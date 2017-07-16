
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("south");
  SetShort("before a high staircase");
  SetLong(
          "A stone cut staircase starts in this section of the tower "
          "and inclines upward into the tower. The torches line the "
          "walls and rise with the starway adjusting a perfect height "
          "from the floor with each step. The walls that create the "
          "hallway wrap around the steps and rise upward into the "
          "tower.");
  SetExits( ([
            "south"            : TOWER_ROOMS "twer02",
           ]) );
  SetInventory( ([ 
                TOWER_NPC "zombie" : 1,
				TOWER_OBJ "rtorch" : 1,
				TOWER_OBJ "stairs01" : 1,
           ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames."
           ]) );
  SetItems( ([
     "torch"     : "Made of wood it rests near the wall as if "
                   "it was floating. It burns in black glowing "
                   "flames.",
     "steps"     : "The steps are small cut stones that rise upward "
                   "into the tower.",
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other.",
     "walls"      : "The tower wall is made of perfectly cut black "
                    "stone slabs.",
    ({ "ground", "floor" }) : "The ground has been lined with a "
                               "red carpet and it lines the walls "
                               "edge to edge.",
    ({ "carpet"  }) : "The red carpet is plain and "
                      "simple. It covers the floor "
                      "wall to wall.",
              ]) );
  SetItemAdjectives( ([
    "ceiling" : ({ "flat","bare","stone" }),
    "carpet" : ({ "red" }),
    "floor" : ({ "carpet","red" }),
    "ground" : ({ "carpet","red" }),
    "walls" : ({ "black","stone"}),
  ]) );
}