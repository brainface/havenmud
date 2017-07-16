#include <lib.h>
#include <domains.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "southeast" : ESTERGRYM_VIRTUAL "northroad/0,20",
    "northwest" : TULU_ROOM "path02",
  ]) );
  SetShort("along a desolate path");
  SetLong("A thin path breaks from the road here, passing to the northwest towards a small hill. "
          "To the southeast, the path meets up with the North Road leading along the eastern edge of "
          "Kailie's main continent. To the east, the Estergrym Mountains rise and tower over the land, "
          "while to the west the plains and rolling hills of the lands of Estergrym spread out over "
          "the horizon."
          );
  SetItems( ([
    ({ "mountain", "mountains" }) : "The Estergrym Mountains tower to the east.",
    "path" : "The path leads to the northwest from the North Road which lies to the southeast.",
    ]) );
  SetItemAdjectives( ([
    "mountain" : ({ "estergrym" }),
    "path"     : ({ "thin" }),
    ]) );
  SetSmell( ([
    "default" : "The crisp air of the Estergrym Mountains blows down from the eastern spires.",
    ]) );
  SetListen( ([
    "default" : "An odd stillness hangs around the path.",
    ]) );
}              