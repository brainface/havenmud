//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetShort("within Lake Rantera");
  SetClimate("arid");
  SetLong(
    "The dark waters of Lake Rantera are shallow enough here to "
    "provide a view of the silt-covered bottom. The lake deepens "
    "to the east, and to the north runs the River Itro. Westward "
    "stands the desert, and nearer, some buildings."
  );
  SetItems( ([
    ({ "water", "waters", "lake" }) :
    "The water seems a dark agate color on account of the mud, but "
    "when scooped from the river it is mostly clear and fresh.",
    ({ "bottom", "silt" }) :
    "The silt is black and squelches when one puts weight onto it.",
    ({ "desert", "buildings", "building" }) : 
    "These things are too far away to make out clearly.",
  ]) );
  SetItemAdjectives( ([
  "waters" : ({ "dark" }),
  "bottom" : ({ "silt-covered" }),
  ]) );
  SetProperty("coastal",1);
  SetListen("The waves lap with the calmness of a millpond.");
  SetSmell("The river gives off a muddy, fishy fragrance.");
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/shark" : 10,
      DIR_STD "fish/boot" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
  SetExits( ([
    "east"  : LAKE_ROOM "/5d",
    "west"  : LAKE_ROOM "/5b",
    "south"  : LAKE_ROOM "/6c",
    "north" : LAKE_ROOM"/4c",
  ]) );
}
