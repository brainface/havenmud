/*  Portia  Ruins  10-10-98
     A room in the village. (will be the room to enter the dark-elf city)
*/

#include <lib.h>
#include <domains.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "6,-3",
        "south" : RUINS_ROOMS + "6,-5",
          ]) );
  SetInventory( ([
            ]) );
  SetSmell( ([
      "default" : "The air smells of smoke.",
          ]) );
  SetListen( ([
        "default" : "Footsteps can be heard.",
       ]) );
  SetLong("This area seems to have been the heart of the village. "
          "To the west lies a large stone blocking the way, while "
          "to the east there lies a single stone wall. The walkway "
          "continues through the village to the north and to the "
          "south. Oddly, this area seems to have been cleaned up, and "
          "it has what looks to be a row of flowers planted purposefully "
         "in front of the large wall to the east. "
    );
  SetItems( ([
      ({"village", "walkway", "area"}) :  (:GetLong:),
      "stone" : "The stone blocking the way to the west is huge.",
      "wall" : "The wall is very large and appears to have a fireplace in it.",
       ({"row", "flowers", "row of flowers", "flower" }) : "The flowers have been planted here "
                         "by some caring person.",
      ({"fireplace" }) : "The fireplace is rather large.",
     ({"staircase" }) : "The obsidian staircase leads down to Malveillant.",
        ]) );
  SetItemAdjectives( ([
        "walkway" : "dusty",
         "stone" : ({"huge", "large"}),
        "wall" : ({"single", "stone", "large"}),
        "fireplace" : "large",
        "staircase" : ({"huge", "spiral", "obsidian"}),
        ]) );
  }
