#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : LISHT_ROOM "elf/rr3",
    "east" : LISHT_ROOM "elf/rr1",
    ]) );
  SetShort("on the River Road");
  SetLong(
    "The River Road continues to the east and west from here. To the "
    "east the road leads off to the flood plains that serve to feed the "
    "city. To the east lies the wall that seperates the slave quarter "
    "from the main city. An impressive iron gate sits, blocking off "
    "the outlying lands at night and defending the main city from harm. "
    "To the north looks a friendly and inviting looking home."
    );
  SetSmell("The smell of the flood plains is less defined at this distance.");
  SetItems( ([
    ({ "road" }) : "The road continues east and west.",
    ({ "plain", "plains" }) : "The flood plains lie to the east.",
    "wall" : "The city wall is a massive sandstone affair that seems to be "
             "very secure.",
    "gate" : "The gate is a large iron porticulis that could likely hold off "
             "a medium sized invasion.",
    ({ "home", "house" }) : "This house seems to be welcome and inviting.",
    ]) );
  SetItemAdjectives( ([
    "road"  : ({ "river" }),
    "plain" : ({ "flood" }),
    "wall"  : ({ "city", "sandstone" }),
    "gate"  : ({ "iron", "impressive" }),
    "home"  : ({ "friendly", "inviting" }),
    ]) );
  SetEnters( ([
    "home" : LISHT_ROOM "elf/newbie",
    ]) );
}
