#include <lib.h>
#include "../gurov.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : GUROV_ROOM "cr8",
    "east" : GUROV_ROOM "pr2",
    ]) );
  SetShort("the Prince's Road near Center Road");
  SetLong(
    "The Prince's Road continues on to the east from here, and to the "
    "west it meets up with the Center Road that travels through town. "
    "Further to the east, the road passes in front of the Prince's Keep, "
    "and at its very edge the road dead-ends in front of the town wall. "
    "The road here appears wide enough for a large procession."
    );
  SetItems( ([
    "road" : "The road is wide enough for many soldiers to march down.",
    ]) );
  SetSmell("The smells of the town mix to form a pleasant smell of home.");
  SetListen("The business of the city combines to form a background noise.");
  SetInventory( ([
    GUROV_NPC "citizen" : 2,
    ]) );
}