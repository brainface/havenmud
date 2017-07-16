
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("west, north");
  SetShort("a turn in the hallway");
  SetLong(
          "The hallway bends in the corner leaving only north "
          "and west passage. Black burning torches line the "
          "walls in the tower. A dark red carpet lines the "
          "ground and bends with the hallways turn.");
  SetExits( ([
            "west"            : TOWER_ROOMS "twer01",
            "north"           : TOWER_ROOMS "twer03",   
           ]) );
  SetInventory( ([ 
				  TOWER_OBJ "rtorch" : 2,
              ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames."
           ]) );
  SetItems( ([
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other.",
     "torch"     : "Made of wood it rests near the wall as if "
                   "it was floating. It burns in black glowing "
                   "flames.",
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
    "" : ({ "","","" }),
    "" : ({ "","","" }),
    "" : ({ "","","" }),
  ]) );
}