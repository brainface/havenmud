#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : YOZRATH_ROOM "gate3",
    "east" : YOZRATH_ROOM "baz2",
    ]) );
  SetLong(
    "The Bazaar Road heads east and west from here. To the west, the road "
    "connects with the Gate Road to wander througout the City of Yozrath. "
    "To the east lies a large wooden building that serves as an inn. Though "
    "Yozrath gets little tourist traffic, the inn seems to be doing well. "
    "To the west lies a four way intersection that also leads to the Oasis "
    "at Yozrath."
    );
  SetShort("the Bazaar Road east of an intersection");
  SetSmell("Weird smells come from the east.");
  SetListen("Even from here the conversation of the bazaar is a dull roar.");
}
