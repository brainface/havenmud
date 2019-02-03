#include <lib.h>
#include <std.h>
#include "../gurov.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetExits( ([
    "east"  : GUROV_ROOM "dock2",
    "north" : GUROV_ROOM "bay1",
    ]) );
  SetSpeed(5);
  SetFish( ([
    DIR_STD "fish/guppy" : 100,
    DIR_STD "fish/trout" : 50,
    DIR_STD "fish/boot" : 1,
    ]) );
  SetChance(25);
  SetMaxFishing(4);  
  SetShort("the docks in front of the Shipwright's Warehouse");
  SetLong(
    "The docks end here in front of a large warehouse.  Judging from "
    "the sign of the ship hanging over the large door, the warehouse "
    "houses the Principality's main shipwright. While other buildings "
    "line the docks, the warehouse is the only one that seems accessable "
    "to the general public. To the east, the docks connect with the Center "
    "Road that leads through town. To the north lies the Gurov Bay."
    );
  SetItems( ([
    "warehouse" : "The warehouse is home to the local shipwright.",
    "docks"     : "The docks are sturdy wood, meant to withstand the time.",
    ]) );
  SetEnters( ([
    "warehouse" : GUROV_ROOM "shipseller",
    ]) );
  SetSmell("The smell of rotting ship taints the air.");
  SetListen("The water gently crashes against the docks.");
}
