#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_ROOM;
inherit LIB_FISHING;

static void create() {
  ::create();
  SetProperty("shallows", 1);
  SetShort("in the Gurov Bay");
  SetLong(
    "The Gurov Bay stretches out towards the Northern Sea from here. Off "
    "to the south the water laps up against the Gurov Docks. The icy cold "
    "waters of the Northern Sea threaten all who travel them."
    );
  SetSmell("The icy cold waters smell of the shore nearby.");
  SetListen("The waters of the sea lap against everything that floats.");
  SetExits( ([
    "north" : GUROV_ROOM "bay3",
    "south" : GUROV_ROOM "bay1",
    "east"  : GUROV_ROOM "bay5",
    ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    ]) );
  SetChance(25);
  SetMaxFishing(4);
}