#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "west" : LISHT_ROOM "elf/rr2",
    "east" : LISHT_ROOM "elf/fp9",  
    ]) );
  SetShort("the end of River Road");
  SetLong(
    "To the east lies the flood plains of Lisht, the source for many of the "
    "foodstuffs that keep the city well fed. A small stone road leads west "
    "towards the city from here, leading from the plains to the gate that "
    "connects the slave quarter to the respectible citizenry of Lisht. "
    "A rundown building sits by the side of the road. It seems to be the "
    "local office of notices."
    );
  SetItems( ([
    ({ "plain", "plains" }) : "The flood plains to the east are well tended "
                              "agricultural areas.",
    ({ "road" }) : "The small stone road leads to the west.",
    ({ "gate" }) : "The gate is too far to the west to see from here.",
    ({ "building", "office" }) : "This is the local post office. From here, "
                                 "notices and announcements can be checked.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "rundown" }),
    ]) );
  SetEnters( ([
    "building" : LISHT_ROOM "elf/post",
    ]) );
  SetSmell("The smell of growth and mud is everywhere.");
  SetListen("The tone is subdued in the slave quarter.");                                                               
}
