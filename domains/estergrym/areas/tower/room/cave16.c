
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("northwest, southwest");
  SetShort("a bend in the cave");
  SetLong(
          "Small bits and pieces of soil have littered the ground "
          "in this section of the tunnel. A large chunk of the "
          "east wall has been sliced to make a solid rock column and "
          "supports the ceiling with its crude design. This "
          "area seems to be under severe water damage.");
  SetInventory( ([ 
               TOWER_OBJ "parchment" : 2, 
			     ]) );
  SetExits( ([
            "northwest"  : TOWER_ROOMS "cave17",
            "southwest"  : TOWER_ROOMS "cave14",
           ]) );
  SetSmell( ([
            "default" : "It smells like wet soil.",
           ]) );
  SetListen( ([
            "default" : "Faint dripping water is heard."
           ]) );
  SetItems( ([
     "ceiling" : "The ceiling has few missing pieces out of it. It appears "
                 "moist and soaked with water. Occasional drops of "
                 "water make its way to the ground.",
     "walls"   : "The walls are made of an uneven flat rock that support "
                 "the ceiling. An irregularly shaped column reaches "
                 "up to the damaged ceiling.",
     "soil"    : "Behind the natural rock the cave forms is this "
                 "black dry soil. A few pieces of it are scattered "
                 "about the floor.",
     "east wall" : "It has a column carved right out of the wall.",
    ({ "column" })  : "The rock column has been carved "
                      "out of the eastern wall and "
                      "stands high supporting the ceiling. "
                      "It has no pattern whatsoever in "
                      "design, it appears to have been "
                      "carved from swords and axes. "
                      "Tears and cuts along the rock "
                      "column are up and down the round "
                      "shaped surface.",

    ({ "ground", "floor" }) : "The ground is covered in a thin layer "
                               "of water. Few chunks of the ceiling "
                               "have made their way to the ground "
                               "surface.",
		"design" : "Looks as though someone fingerpainted the "
		           "Kylin emblem in blood.",
	    "blood"  : "The blood is black from age.",
		"emblem" : "The emblem is that of the holy order of "
		           "Kylin but drawn in blood. It appears to "
				   "be a warning. The Kylin Holy Symbol is a "
				   "balance (a set of equal scales) with a "
				   "dragon intertwined.",
              ]) );
  SetItemAdjectives( ([
    "column" : ({ "rock" }),
    "design" : ({ "crude" }),
    "blood" : ({ "black","aged" }),
    "emblem" : ({ "kylin","crude" }),
    "wall" : ({ "rock" }),
    "walls" : ({ "rock" }),
    "soil" : ({ "black","dry" }),
  ]) ); 
 }
