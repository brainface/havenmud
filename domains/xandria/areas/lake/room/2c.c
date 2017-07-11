//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_FISHING;

static void create() {
  fishing::create();
  SetShort("outside of a ceramics workshop");
  SetClimate("arid");
  SetLong(
    "The entrance to a long building is here in front of a muddy "
    "clay bed, where people come daily to dig out material for "
    "making their ceramics. A constant heat comes from the workshop. "
    "To the east stands Lake Rantera, and another building is to the "
    "south of here. There seems to also be a dock of some sort that way."
  );
  SetItems( ([
    ({ "water", "waters", "lake" }) :
    "The water seems a dark agate color on account of the mud, but "
    "when scooped from the river it is mostly clear and fresh.",
    ({ "bed" }) :
    "The clay bed has holes gauged into it from people coming for "
    "years to remove the clay.",
    ({ "workshop", "buildings", "building" }) : 
    "The building here seems to be a workshop for making ceramics. "
    "It is a low building built from mud-brick. Another one stands "
    "to the south of this place.",
    "dock" : "The dock is south of this place."
  ]) );
  SetItemAdjectives( ([
  "bed" : ({ "muddy", "clay" }),
  "lake" : ({ "rantera" }),
  "building" : ({ "long" }),
  "workshop" : ({ "ceramic" }),
  ]) );
  SetListen("You can hear the calling of water birds in the distance.");
  SetSmell("The air smells dry and dusty.");
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/shark" : 10,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
  SetExits( ([
    "east"  : LAKE_ROOM "/2d",
    "south"  : LAKE_ROOM "/3c",
    "north" : LAKE_ROOM "/1c",
  ]) );
  SetEnters( ([
    ({"building", "workshop"}) : LAKE_ROOM "/2b",
  ]) );
}
