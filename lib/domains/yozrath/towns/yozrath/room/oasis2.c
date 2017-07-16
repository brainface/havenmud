#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a blessed area of the Oasis at Yozrath");
  SetClimate("arid");
  SetProperty("no magic", 1);
  SetProperty("no attack", 1);
  SetProperty("no bump", 1);
  SetExits( ([
    "north" : YOZRATH_ROOM "oasis3",
    ]) );
  SetLong(
    "Long ago, this section of the Oasis at Yozrath was blessed by the Imam of Yozrath "
    "to be forever protected from harm. It is said that no harm can come to those who "
    "rest here. A few small palm trees offer some shade from the harsh desert sun, but "
    "the area is primarily devoid of interesting sights."
    );
  SetSmell("A faint smell of rotting dates hangs in the air.");
  SetListen("The area is peaceful and quiet.");
  SetItems( ([
    ({ "tree", "trees" }) : "The few small palm trees that are present are "
                            "sufficient only to provide limited shade.",
    ]) );
  SetItemAdjectives( ([
    "tree" : ({ "small", "palm" }),
    ]) );
}
