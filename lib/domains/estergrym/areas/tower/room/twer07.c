
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("east");
  SetShort("in a small study");
  SetLong(
          "This small study has very few furnishings decorating "
          "it. An altar dressed along the west wall has "
          "an inkwell atop it covered in black dried ink. Torches "
          "line the walls in the same fashion as the hallways. "
          "The red carpet lines the floor covering the entire "
          "study with its simple look.");
  SetExits( ([  
            "east"     : TOWER_ROOMS "twer06",
           ]) );
  SetInventory( ([ 
                  TOWER_NPC "apprentice" : 1,
                  TOWER_OBJ "rtorch" : 2, 
 		  ]) );
  SetSmell( ([
            "default" : "The smell of dark magic is abundant.",
           ]) );
  SetListen( ([
            "default" : "The torches crackle in black flames.",
           ]) );
  SetItems( ([
     "altar"     : "The altar appears to be used for a desk "
                   "for some simple studying or writing. It "
                   "has an inkwell atop of it covered in "
                   "black dried ink. It is very simply made "
                   "out of the same slabs that make up this "
                   "tower.",
     "inkwell"   : "It rests on the altar covered in dried "
                   "black ink. It appears to be used quite "
                   "often.",
     "doorway"   : "The doorway leads east, out into the hallway.",
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