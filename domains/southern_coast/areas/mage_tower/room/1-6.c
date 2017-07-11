#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a passage with a stairwell");
  SetExits( ([
    "west"  : "1-5",
    "south" : "1-1",
    "east"  : "1-3",
    ]) );
  SetInventory( ([
    TOWER_OBJ "stair-1" : 1,
    TOWER_NPC "spectre" : 1,
    ]) );
  SetLong("The hallway opens here into a wide room of sorts.  The "
          "room has little in the way of notable features except "
          "for a huge obsidian stairwell leading into the upper "
          "reaches of the tower. To the south the hallway leads "
          "back to the entrance of the tower, while to the east "
          "and west the tower seems to curve back onto itself.");
  SetSmell( ([
    "default" : "Light dust flitters in the air.",
    ]) );
  SetListen( ([
    "default" : "The grueling silence of the tower is the only sound.",
    ]) );
}
