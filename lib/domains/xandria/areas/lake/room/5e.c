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
    "The dark waters of Lake Rantera are here are deep enough "
    "to allow safe passage of boats. The banks stand on both "
    "eastern and western sides, and the River Itro runs from the "
    "north into this place. Around the banks stand small buildings "
    "just on the edge of the desert."
  );
  SetItems( ([
    ({ "water", "waters", "lake" }) :
    "The water seems a dark agate color on account of the mud, but "
    "when scooped from the river it is mostly clear and fresh.",
    ({ "river", "itro" }) : 
    "The river lies north of this lake.",
    ({ "banks", "bank", "sides", "side" }) :
    "The banks of Lake Rantera stand greenly to the east and west.",
    ({ "desert", "buildings", "building" }) : 
    "These things are too far away to make out clearly.",
  ]) );
  SetItemAdjectives( ([
  "waters" : ({ "dark", "deep" }),
  ]) );
  SetProperty("shallows", 1);
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
    "east"  : LAKE_ROOM "/5f",
    "west"  : LAKE_ROOM "/5d",
    "south"  : LAKE_ROOM "/6e",
    "north" : LAKE_ROOM "/4e",
  ]) );
}
