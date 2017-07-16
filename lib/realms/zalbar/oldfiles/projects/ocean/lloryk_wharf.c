#include <lib.h>
#include "../path.h"
#include <domains.h>
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("a wharf");
  SetExits( ([
    "north" : LLORYK "room/hb1",
    "south" : INNERSEA_VIRTUAL "ocean/-88,6",
    ]) );
  SetLong("The Shire Bay spreads out to the south from here, leading "
          "off into the distance. The farmland spreads out to the north "
          "and east from here. ");
  SetSmell( ([
    "default" : "Saltwater mixes with farm products to form an "
                "interesting smell.",
    ]) );
  SetListen( ([
    "default" : "Waves gentle crash against the shore.",
    ]) );
  SetInventory( ([
    LLORYK "npc/shipseller" : 1,
    LLORYK "npc/hurley"     : 1,
    LLORYK "obj/yacht"      : 1,
    ]) );
  SetProperty("coastal", 1);
  SetSpeed(5);
  SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
    ]) );
  SetChance(25);
  SetMaxFishing(12);
}
