
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("south");
  SetShort("third floor staircase");
  SetLong(
          "The red carpet runs up the several steps on the staircase "
          "that lead up into the tower. Torches line the walls "
          "burning in dark black flames. The staircase is identical "
          "to the others and wraps around the north wall upward into the "
          "above floors of the tower.");
  SetExits( ([
            "south" : TOWER_ROOMS "twer06",
           ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames.",
           ]) );
  SetInventory( ([ 
	                TOWER_OBJ "stairs05" : 1 ,
					TOWER_OBJ "rtorch" : 1,
					]) );
  SetItems( ([
     "torch"     : "It rests along the wall with no support, as "
                   "if floating.",
     "steps"     : "The steps are small cut stones that lead up to "
                   "the upper levels. Every step is covered in red "
                   "carpeting.",
     "ceiling"   : "The ceiling is flat and bare. It is composed "
                   "of black stone cut slabs.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other and "
                   "follow the staircase up.",
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