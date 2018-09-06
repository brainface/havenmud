#include <lib.h>
#include <domains.h>
#include "../sheep.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("a grassy beachfront");
  SetProperty("coastal", 1);
  SetExits( ([
    "west" : INNERSEA_VIRTUAL "ocean/13,-18",
    "east" : SHEEP_ROOM "field1",
    ]) );
  SetLong(
    "Directly to the west the shore meets the Ruined Sea in a calm and peaceful caress. "
    "A small path leads east up away from the water towards what appears to be a small "
    "farm. The area has been cleared of trees and the grass, while wild, appears to be "
    "cropped short."
    );
  SetSmell("There is a hanging odor of dung that seems to permeate the air.");
  SetListen("Soft bleating comes from the east, while the soft crash of the sea comes from the beach.");
  SetInventory( ([
    SHEEP_OBJ "fishingboat" : 1,
    ]) );
  //mahk: mucking around
   SetChance(25);
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/elban/wooly_whiting" : 5,
   ]) );
}

