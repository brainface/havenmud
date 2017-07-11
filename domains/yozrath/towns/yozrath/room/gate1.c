#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("at the Northern Gate to the City of Yozrath");
  SetExits( ([
    "north" : "/domains/yozrath/virtual/desert/0,2",
    "south" : YOZRATH_ROOM "gate2",
    "east"  : YOZRATH_ROOM "mos1",
    ]) );
  SetLong(
    "The Northern Gate leads out onto the hostile desert to the north. "
    "To the east, the Mosque Road leads directly to the center of the "
    "Kylin faith in the desert, the Holy Mosque of Yozrath. Off to the "
    "south, the road continues and leads to the heart of the city. Various "
    "buildings line the road, but none appear accessable from here."
    );
  SetItems( ([
    "gate" : "The Northern Gate leads out to the wide expanse of the desert.",
    "mosque" : "The Mosque of Yozrath lies to the east.",
    ({ "building", "buildings" }) : "Various buildings line the road, but "
                                    "are not accessable from here.",
    ]) );
  SetSmell("The city has a fresh smell compared to many cities.");
  SetListen("The sounds of city life are reassuring and comforting.");
  SetInventory( ([
    YOZRATH_NPC + "guard" : 2,
    ]) );                               
}
