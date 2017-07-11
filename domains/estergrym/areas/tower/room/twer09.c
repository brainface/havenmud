
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("a winding staircase");
  SetLong(
          "The winding staircase runs up the tower walls in a circular "
          "fashion. The steps are lined with a simple red carpeting and "
          "the torches burn even darker with their black flames. The top "
          "of the staircase is nearby revealing a ledge in the distance.");
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames.",
           ]) );
  SetInventory(([ 
                  TOWER_NPC "skeleton1" : 1,
                  TOWER_NPC "zombie" : 1,
                  TOWER_NPC "mummy2" : 1,
                  TOWER_OBJ "stairs07" : 1,
				  TOWER_OBJ "rtorch" : 1,
				  ]));
  SetItems( ([
     "ledge"     : "The ledge above appears to be where this staircase "
                   "ends.",
     "steps"     : "The steps are small cut stones that lead to "
                   "the different levels. Every step is covered in red "
                   "carpeting.",
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs and composed of the "
                   "steps in the winding staircase.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other and "
                   "follow the staircase up and down lining the walls.",
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