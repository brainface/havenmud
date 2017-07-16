
#include <lib.h>
#include "../defs.h"
#include <domains.h>


inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetObviousExits("east, southwest");
  SetShort("upon a fallen soldier");
  SetLong(
          "At the bend of the turn southwest is the skeletal remains "
          "of a fallen soldier. Cobwebs have been mended with his "
          "armour and gear. This tunnel leads on toward the east "
          "near the edge of a cliff inside the cave. The ceiling "
          "has tiny specks of a dark red gypsum.");
  SetInventory( ([ 
                  TOWER_OBJ "shield1" : 1,
                  TOWER_OBJ "cigar"   : 4, 
				  ]) );
  SetExits( ([
            "east"           : TOWER_ROOMS "cave06",
            "southwest"      : TOWER_ROOMS "cave04",   
           ]) );
  SetSmell( ([
            "default" : "It smells dry and clean.",
           ]) );
  SetListen( ([
            "default" : "A small falling rock is heard."
           ]) );
  
  SetItems( ([
     "ceiling" : "It is rising to the east to a doorway.",
     "doorway" : "It is a natural cave doorway but it is located "
                 "more east.",
     "skull"   : "It has a dent in the bleached white "
	             "skull like from an axe.",
     "dent"    : "A former mortal blow.",
     "walls"   : "The walls are composed of a dark speckled black and "
                 "packed clay.",
	 "clay"    : "The black speckled clay creates the walls "
	             "here.",
     "cliff"   : "The cliff is to the east and prevents any falling "
                 "down.",
     "remains" : "It is just a skeleton with a dent in his skull.",
     "skeleton": "It rests on the north wall sitting upright. It "
	             "devoid of any treasures.",
     "gypsum"  : "It is in the cavern rocks, this particular size of "
                 "gypsum is worthless.",
    ({ "ground", "floor" }) : "The floor ramps up past the remains "
                              "to the east upward toward the ceiling.",
              ]) );
    SetItemAdjectives( ([
    "ceiling" : ({ "rising" }),
    "doorway" : ({ "natural","cave","east" }),
    "skull" : ({ "white","bleached" }),
    "walls" : ({ "dark","clay","speckled","black" }),
    "cliff" : ({ "east" }),
    "skeleton" : ({ "sitting","treasureless" }),
    "gypsum" : ({ "rock" }),
    "ground" : ({ "upward" }),
	"clay" : ({ "dark","speckled","black" }),
  ]) );
  }
