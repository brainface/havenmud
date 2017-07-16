
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("west, south, northwest");
  SetShort("a fork in the cave");
  SetLong(
          "The cavern splits into three directions all composed "
          "of the spotted clay that makes this cave. The ceiling "
          "has been lowered to an average height. A torch sconce "
          "rests bolted on the eastern wall which is currently "
          "empty. This section of the tunnel is completely "
          "bare.");
  SetInventory( ([ 
                TOWER_NPC "skeleton2" : 2,
				 ]) );
  SetExits( ([
            "west"      : TOWER_ROOMS "cave08",
            "south"     : TOWER_ROOMS "cave06",
            "northwest" : TOWER_ROOMS "cave09",   
           ]) );
  SetSmell( ([
            "default" : "Nothing particularly gives off a smell.",
           ]) );
  SetListen( ([
            "default" : "An echo is heard from the south."
           ]) );
  
  SetItems( ([
     "ceiling" : "It has been well rounded and smoothed showing no "
                 "deviation in design.",
     "doorway" : "It is directly south leading toward the opening.",
     "walls"   : "The walls are composed of a dark speckled black and "
                 "packed clay. Some vertical ridges have been made "
                 "in the wall.",
     "opening" : "It is to the south.",
     "sconce"  : "It is empty. Some torch residue is still on the "
                 "sconce proving it was used at some point.", 
    ({ "ground", "floor" }) : "It is made of a dark packed clay.",
     "clay"    : "The clay creates the tunnel boundaries.",
	]) );
    SetItemAdjectives( ([
    "clay" : ({ "black","spotted","dark" }),
    "sconce" : ({ "torch" }),
  ]) );
}