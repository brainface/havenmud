//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in a muddy alley between two buildings");
  SetClimate("arid");
  SetLong(
    "This is a muddy alley formed by the walls of the two workshops "
    "on this side of the lake. Children often play here in the mud, "
    "evidenced by the small footprints here and there. The dunes "
    "of the endless desert begin just to the west, but the way "
    "back to civilization is in the other direction. "
  );
  SetItems( ([
    ({ "alley" }) : (: GetLong :),
    ({ "walls" }) :
    "The mud-brick walls block off the north and south. ",
    ({ "workshop", "workshops" }) :
    "The ceramic workshop is to the north, and the papermaking "
    "workshop is to the south.",
    ({ "footprint", "footprints" }) :
    "The footprints in the mud belong to small children. ",
    ({ "dunes", "dune" }) : "Sandy dunes of the expansive desert.",
    ({ "mud" }) : "Mud coats the ground in all directions. It is marred by "
    "many small footprints.",
  ]) );
  SetItemAdjectives( ([
  "footprints" : ({ "small" }),
  ]) );
  SetListen("You can hear the laughter of playing children.");
  SetSmell("It smells dirty here.");
  SetExits( ([
    "east" : LAKE_ROOM "/4b",
  ]) );
  SetInventory( ([
    LAKE_NPC "urchin" : 2,
  ]) );
}
