#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("near the Oasis at Yozrath");
  SetExits( ([
    "west" : YOZRATH_ROOM "oasis3",
    "east" : YOZRATH_ROOM "gate3",
    ]) );
  SetClimate("arid");
  SetLong(
    "This short path cuts away from the Gate Road and leads towards "
    "the famous Oasis at Yozrath, the center of town and source of "
    "precious water for the residents of the city. In the distance "
    "to the west the Sheik of Yozrath's Palace sits by the Oasis. "
    "To the east, the path joins the Gate Road which leads north and "
    "south through the City of Yozrath."
    );
  SetItems( ([
    "path" : "The path cuts to the west and leads to the Oasis at Yozrath.",
    "oasis" : "The Oasis lies to the west.",
    "road" : "The Gate Road lies to the east, but leads north and south "
             "from there.",
    "palace" : "The Palace of the Sheik lies off to the west.",
    ]) );
  SetItemAdjectives( ([
    "path" : ({ "small", "short", }),
    "oasis" : ({ "famous", }),
    "road"  : ({ "gate" }),
    ]) );
  SetSmell("The smells of water come from the west.");
  SetListen("The rustle of palm branches is inviting.");
}

    