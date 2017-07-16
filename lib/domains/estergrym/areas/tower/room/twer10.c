
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("south");
  SetShort("atop the staircase");
  SetLong(
          "The steps come to an end on the towers fifth floor. A "
          "ledge can be seen to the north overlooking the staircase "
          "leading down. Black flame burning torches line the "
          "bare walls to the south and down the staircase. A "
          "red carpet follows the hallway to the south leading "
          "through an ornate doorway with no door.");
  SetExits( ([
            "south"          : TOWER_ROOMS "twer11",   
           ]) );
  SetInventory( ([ 
                  TOWER_OBJ "stairs08" : 1,
				  TOWER_OBJ "rtorch" : 1,
				  ]) );
 
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames.",
           ]) );
  SetItems( ([
     "torch"     : "It rests along the wall with no support, as "
                   "if floating.",
     ({ "doorway" }) : "The doorway is made of wood "
                   "and provides passage to the south. It has strange "
                   "runes which glow with what appears to be red "
                   "embers.",  
     "ledge"     : "It rests to the north overlooking the staircase.",
     "steps"     : "The steps are small cut stones that lead to "
                   "the south. Every step is covered in red "
                   "carpeting.",
     "ceiling"   : "The ceiling is flat and bare and it is composed "
                   "of black stone cut slabs. It does not rise anymore "
				   "proving the climax of this tower.",
     "torches"   : "Torches burn in black flame, making this "
                   "tower dampen the light here. They line "
                   "the walls three feet apart from each other and "
                   "follow the hallway south and the steps downward.",
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
