#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : PARVA_ROOM "path4",
    "north": PARVA_ROOM "wharf0",
    "south": PARVA_ROOM "wharf2",
    ]) );
  SetShort("along the wharf in Parva");
  SetLong(
    "The sandy road which runs along the waterfront forks here "
    "before a small shrine made from old driftwood and stuccoed "
    "with sea salt and broken bits of shell. To the south stands a "
    "modest obsidian building and the Parvan docks jut out into the "
    "sea, and the road leads both west and north from here."
  );
  SetItems( ([
    "shrine"     : "This is a shrine to the Drowned God, the religion of Damhair.",
    "road"       : "The sandy path is the main road of Parva, despite its shabbiness.",
    "waterfront" : "The ocean, rank with the scent of rotting fish and seaweed, stands just to the east.",
    ({ "salt", "shell", "driftwood", "bits" }) : "The shrine is made of all things given by the sea herself.",
    ({ "docks", "building" }) : "The docks and another shrine stand in the south.",
    ]) );
  SetItemAdjectives( ([
    "road"       : ({ "sandy" }),
    "salt"       : ({ "sea", "broken" }),
    "docks"      : ({ "parvan", "modest", "obsidian" }),
    ]) );
  SetEnters( ([
    "shrine" : PARVA_ROOM "damhair",
    ]) );
  SetSmell("The stench of the ocean assaults the air.");
  SetListen("A strange quiet hangs about the shrine.");
  SetInventory( ([
    ]) );
}
