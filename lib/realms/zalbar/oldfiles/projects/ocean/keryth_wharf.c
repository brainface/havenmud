#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../keryth.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetClimate("arctic");
  SetExits( ([
    "north" : INNERSEA_VIRTUAL "ocean/-152,94",
    "south" : K_ROOM "/road3",
    "west"  : INNERSEA_VIRTUAL "ocean/-153,93",
    "east"  : K_ROOM "/outskirt",
    ]) );
  SetShort("at the shores of the Northern Sea");
  SetSmell("The smell of fish on the shore stinks to the heavens.");
  SetListen("The waves of the Northern Sea gently crash against the docks.");
  SetLong(
    "The docks line the shores of the the sea here. To the south, the "
    "road leads back through town. Off to the east lie what appear to "
    "be the outskirts.  A sign hangs "
    "from a warehouse with a picture of a ship on it. Ramshackle buildings "
    "of all manner line the docks, showing that the goden longships aren't "
    "a unified force but instead local independant raiders. "
    "A wharf juts out into the bay from here."
    );
  SetItems( ([
    ({ "dock", "docks" }) : "The docks are sturdy wooden structures holding "
                            "back the sea.",
    "warehouse"           : "The warehouse is home to the local shipwright.",
    ({ "building", "buildings" })
                          : "The buildings are home to minor raiders.",
    "wharf"               : "The wharf juts out into the bay, a fine place "
                            "to dock ships.",
  "sign" : "The sign hangs on the side of the warehouse and shows "
    "a picture of a goden longship.",
    ]) );
  SetEnters( ([
    "warehouse" : K_ROOM "/warehouse",
    ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    ]) );
  SetChance(25);
  SetMaxFishing(4);  
  SetProperty("coastal", 1);
  SetInventory( ([
    K_OBJ "/k_longship" : 2,
    K_NPC "/godenviking" : 1,
    ]) );
}
