
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("north, west");
  SetShort("third floor atop a staircase");
  SetLong(
          "This hallway forks into two directions in the "
          "tower. To the west an open doorway can be "
          "seen leading into a simple study. A red carpet lines "
          "the walls following the black flamed torches. "
          "A staircase leads down to the second floor "
          "of this black tower.");
  SetExits( ([
            "north"          : TOWER_ROOMS "twer08",
            "west"           : TOWER_ROOMS "twer07",
           ]) );
  SetInventory( ([ 
                  TOWER_NPC "zombie" : 1, 
				  TOWER_OBJ "stairs04" : 1,
				  TOWER_OBJ "rtorch" : 1,
				  ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames.",
           ]) );
  SetItems( ([
     "doorway"   : "The doorway leads to a room in the tower.",
     "study"     : "It lies to the west, with small furnishings.",
     "torch"     : "It rests along the wall with no support, as "
                   "if floating.",
     "steps"     : "The steps are small cut stones that lead down "
                   "to the second floor.",
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other.",
     "walls"      : "The tower wall is made of perfectly cut black "
                    "stone slabs. With the exception of the "
                    "torches, they are bare.",
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
