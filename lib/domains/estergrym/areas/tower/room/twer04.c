
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("south");
  SetShort("atop a staircase");
  SetLong(
          "The steps come to an end leading to a hallway that "
          "leads south. Black flamed torches line the bare walls "
          "and lead south in a perfect pattern. A red carpet "
          "follows the hallway south and covers the steps that "
          "lead to the ground floor of the tower. The entire "
          "tower is engulfed in a magical darkness which lingers "
          "about.");
  SetExits( ([
            "south"         : TOWER_ROOMS "twer05",   
           ]) );
  SetInventory( ([ 
               TOWER_NPC "skeleton1" : 1,
			   TOWER_OBJ "stairs02" : 1,
			   TOWER_OBJ "rtorch" : 1,
 			   ]));
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames."
           ]) );
  SetItems( ([
      "steps"    : "The steps are small cut stones that lead down "
                   "to the first floor of the tower.",
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
                               "edge to edge. It leads up the stairs "
                               "covering them completely.",
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
