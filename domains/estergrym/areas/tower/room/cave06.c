
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("west, north");
  SetShort("the edge of a cliff");
  SetLong(
          "This portion of the cave bends from the west through "
          "a cavern made doorway. The depths below this cliff "
          "stalagmites have formed that contain very sharp tips. The "
          "ceiling has stopped covering the cavern revealing "
          "an open sea of pointy stalagmites that await the "
          "foolish.");
  SetExits( ([
            "west"      : TOWER_ROOMS "cave05",
            "north"     : TOWER_ROOMS "cave07",   
           ]) );
  SetSmell( ([
            "default" : "There is no distinct smell.",
           ]) );
  SetListen( ([
            "default" : "An echo is heard from below the cliff."
           ]) );
  
  SetItems( ([
     "ceiling" : "The ceiling has merged with the wall making the "
                 "north doorway.",
     "doorway" : "The cave formation made this doorway naturally.",
     "walls"   : "The walls are composed of a dark speckled black and "
                 "packed clay. Some vertical ridges have been made "
                 "in the wall.",
     "cliff"   : "It hangs above a sea of stalagmites which would "
                 "welcome a foolish adventurer to meet death.",
     "stalagmites" : "The stalagmites are made from the dripping cave "
                     "water. They have formed into a sharp spear "
                     "like tip which would fatally kill any mortal "
                     "being.", 
	 "stalagmite"  : "Water and stone have made this sharp rock "
	                 "a reality. It is eastward with several more "
					 "in its company.",

    ({ "ground", "floor" }) : "The floor ramps up past the remains "
                              "to the east upward toward the ceiling.",
	]) );
    SetItemAdjectives( ([
    "cliff" : ({ "edge" }),
    "cave" : ({ "cavern" }),
    "stalagmites" : ({ "tips" }),
    "stalagmite" : ({ "tip" }),
 ]) );
}