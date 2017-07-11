//Alex@Haven
//2006
#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create(){
  room::create();
  SetClimate("underground");
  SetAmbientLight(20);
  SetShort("a dry cellar");
  SetLong(
    "This is a tiny root cellar the family uses for storing their "
    "food during the dry season. The dirt floor here is less packed down "
    "and in disarray from the multitude of pots. Soft light tumbles down "
    "from above, and there seems to be something else just to the east, "
    "where the light does not quite reach."
  );
  SetItems( ([
    ({"pot", "pots"}) : "The pots are sticky, and they stink. Some "
    "hold dried sticky fruit, but almost everything is moldy.",
    ({"light"}) : "A lambent sunbeam shimmering with dust particles.",
  ]) );
  SetListen( ([
    "default" : "You hear footfalls and a slithering in the darkness.",
  ]) );
  SetSmell( ([
    "default" : "It smells like someone died in here.",
  ]) );
  SetInventory( ([
    AREA_OBJ + "kumquat" :3,
  ]) );
  SetExits( ([
    "up" : AREA_ROOM "common",
    "east" : AREA_ROOM "den",
  ]) );
}
