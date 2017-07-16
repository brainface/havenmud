#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "north" : YOZRATH_ROOM "gate1",
    "south" : YOZRATH_ROOM "gate3",
    ]) );
  SetShort("along the Gate Road near the Northern Gate");
  SetLong(
    "The Gate Road leads north and south from here. To the south, "
    "the road meets in a four way intersection with paths heading "
    "to the Bazaar and the Oasis at Yozrath. To the north, the road "
    "opens into the Northern Gate, an exit out into the hostile heat "
    "of the desert. The road also curves to the north and leads to the "
    "Mosque in Yozrath, the center of the Kylin faith in the desert."
    );
  SetItems( ([
    "road" : "The Gate Road leads north and south from here.",
    "mosque" : "The Mosque is not visible from here, but is north and east.",
    ]) );
  SetSmell("From the southwest comes the scent of palm dates.");
  SetListen("From the southeast comes the noise of the Bazaar.");                             
}
