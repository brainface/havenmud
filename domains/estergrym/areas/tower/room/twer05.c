
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("north");
  SetShort("a starcase leading up");
  SetLong(
          "This hallway ends and a staircase has been built "
          "leading upward into the tower. It has been lined with "
          "the same red carpet free of debris. Black flaming "
          "torches line both walls which follow the staircase "
          "up to the third floor of the tower.");
  SetExits( ([
            "north"          : TOWER_ROOMS "twer04",
           ]) );
  SetInventory( ([ 
                  TOWER_NPC "mummy2" : 1, 
				  TOWER_OBJ "stairs03" : 1,
				  TOWER_OBJ "rtorch" : 1,
				  ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames."
           ]) );
  SetItems( ([
     "steps"     : "The steps are small cut stones that rise upward "
                   "into the tower.",
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
