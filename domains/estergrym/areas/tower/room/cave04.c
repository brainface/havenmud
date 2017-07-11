
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("northeast, southeast");
  SetShort("a turn in the cave");
  SetLong(
          "This section veers to the northeast or back southeast. "
          "The ground is composed of speckled, packed blackened clay. "
          "Clay walls round out and bend upward to create the smooth "
          "surfaced ceiling.");
  SetInventory( ([ 
               TOWER_NPC "zombie" : 2 
			   ]) );
  SetExits( ([
            "northeast"      : TOWER_ROOMS "cave05",
            "southeast"      : TOWER_ROOMS "cave03",   
           ]) );
  SetSmell( ([
            "default" : "It smells damp and moist.",
           ]) );
  SetListen( ([
            "default" : "Hollow drops in puddles are heard."
           ]) );
  SetItems( ([
     "wall"    : "The wall is made of a speckled black clay. They "
	             "are devoid of any decor.",
     "ceiling" : "It has risen to an equal height from the floor.",
     "clay"    : "The speckled clay makes up the ground, it appears "
	             "to be just be slightly aged soil.",
	 "soil" : "It composes this turn in the cave.",
	 "turn" : "The turn in the cave bends from southeast to northeast.",
     "walls"   : "The walls are composed of a dark speckled black and "
                 "packed clay.",
    ({ "ground", "floor" }) : "The floor has been packed down to a dark "
                               "gray clay. It has been smoothed from age.",
              ]) );
  SetItemAdjectives( ([
    "wall" : ({ "speckled","black","clay" }),
    "ceiling" : ({ "rising" }),
    "clay" : ({ "dark","speckled","gray" }),
    "soil" : ({ "aged" }),
    "turn" : ({ "cave" }),
    "walls" : ({ "clay","speckled","dark" }),
    "ground" : ({ "dark","gray","clay" }),
  ]) ); 
 }