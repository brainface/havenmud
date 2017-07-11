#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "north" : PARVA_ROOM "wharf3",
    "west"  : PARVA_ROOM "path3",
    "south" : PARVA_ROOM "wharf5",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The path leading through Parva ends here at a crossroads at the wharf. "
    "To the east stands the sea and the docks, and on the western edge of "
    "the path is a dilapidated drydock. The roads lead north and south along "
    "the shore as well as to the west, out of the city."
  );
  SetItems( ([
    "drydock" : "The drydock sits to the west, a place where new ships can be "
                "purchased, repaired, or outfitted.",
    ({"path", "road", "roads"}) :
    "The shabby dirt roadways are the main roads of Parva.",
    "sea" : "The smelly ocean laps against the wharf peaceably.",
     ]) );
  SetItemAdjectives( ([
    "drydock" : ({ "dilapidated" }),
    ]) );
  SetEnters( ([
    "drydock" : PARVA_ROOM "drydock",
    ]) );
  SetSmell("The stench of the ocean assaults the air.");
  SetListen("Loud noises come from the drydock.");
  SetInventory( ([
    ]) );
}

