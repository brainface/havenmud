#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetExits( ([
    "south" : YOZRATH_ROOM "gate5",
    "north" : YOZRATH_ROOM "gate3",
    ]) );
  SetLong(
    "The Gate Road leads north and south from here. To the north, the "
    "road forms a four way intersection that leads to both the Bazaar "
    "and the Oasis at Yozrath. To the south however, the Gate Road "
    "leads to the Southern Gate, which opens to the wide and empty desert. "
    "Lining the road are buildings of various shapes and sizes, but none "
    "appear to be accessable from here."
    );
  SetItems( ([
    "road" : "The road leads north and south from here.",
    ({ "building", "buildings" }) : "The buildings are many and varied, but "
                                    "sadly inaccessable.",
    ]) );
  SetSmell("The smells of the city taint the air.");
  SetListen("Even from this distance, the sounds of the bazaar can be faintly heard.");
  SetShort("along the Gate Road near the Southern Gate");                                    
}
