#include <lib.h>
#include <std.h>
#include "../gurov.h"

inherit LIB_FISHING;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetProperty("coastal", 1);
  SetShort("the wharf in the Gurov Bay");
  SetLong(
    "The Gurov Bay stretches out towards the Northern Sea from here. Off "
    "to the south the water laps up against the Gurov Docks. The icy cold "
    "waters of the Northern Sea threaten all who travel them. The wharf "
    "juts out into the bay, challenging the water to overtake it."
    );
  SetSmell("The icy cold waters smell of the shore nearby.");
  SetListen("The waters of the sea lap against the wharf.");
  SetExits( ([
    "north" : GUROV_ROOM "bay5",
    "south" : GUROV_ROOM "dock2",
    "west"  : GUROV_ROOM "bay1",
    "east"  : GUROV_ROOM "bay7",
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
    GUROV_NPC "ferrycaptain" : 1,
    GUROV_OBJ "icebreaker" : 1,
  ]) );
}

