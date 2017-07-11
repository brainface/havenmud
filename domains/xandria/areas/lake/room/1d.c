//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
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
  SetExits( ([
    "east"  : LAKE_ROOM "/1e",
    "west"  : LAKE_ROOM "/1c",
    "south"  : LAKE_ROOM "/2d",
    "north" : "/domains/xandria/virtual/river/-1,-50",
  ]) );
}
