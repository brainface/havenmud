#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetExits( ([
    "north" : GUROV_ROOM "bay4",
    "south" : GUROV_ROOM "cr9",
    "east"  : GUROV_ROOM "dock3",
    "west"  : GUROV_ROOM "dock1",
    ]) );
  SetShort("alongside the Gurov Bay");
  SetSmell("The smell of fish on the shore stinks to the heavens.");
  SetListen("The waves of the Northern Sea gently crash against the docks.");
  SetLong(
    "The docks line the shores of the Gurov Bay here. To the south, the "
    "Center Road leads through town. Off to the east lies what appears to "
    "be a tavern, while to the west a large warehouse sits.  A sign hangs "
    "from the warehouse with a picture of a ship on it. Ramshackle buildings "
    "of all manner line the docks, housing various shipping concerns of both "
    "local ownership and those far-flung trading empires of the south. "
    "A wharf juts out into the bay from here."
    );
  SetItems( ([
    ({ "dock", "docks" }) : "The docks are sturdy wooden structures holding "
                            "back the sea.",
    "tavern"              : "The tavern known as the Whiny Wench lies off to "
                            "the east.",
    "warehouse"           : "The warehouse is home to the local shipwright.",
    ({ "building", "buildings" })
                          : "The buildings are warehouses and other shipping "
                            "concerns.",
    "wharf"               : "The wharf juts out into the bay, a fine place "
                            "to dock ships.",
    ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);  
  SetInventory( ([
    GUROV_NPC "t_fisher" : 1,
    ]) );
}
