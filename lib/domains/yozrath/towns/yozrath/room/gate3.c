#include <lib.h>
#include "../yozrath.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("along the Gate Road in Yozrath");
  SetExits( ([
    "north" : YOZRATH_ROOM "gate2",
    "south" : YOZRATH_ROOM "gate4",
    "west"  : YOZRATH_ROOM "oasis1",
    "east"  : YOZRATH_ROOM "baz1",
    ]) );
  SetLong(
    "The Gate Road leads to the north and south from here, travelling from "
    "the North Gate to the South Gate which lead out into the open desert. "
    "To the west lies the Oasis at Yozrath, the central water source for "
    "the Sheikdom. To the east lies the Yozrath Bazaar, a strange place "
    "where nearly anything can be had for the right price. Several small "
    "buildings line the road here, but none appear to be of more than "
    "passing interest."
    );
  SetItems( ([
    ({ "building", "buildings" }) : "The buildings appear to be homes and "
                                    "other non-noteworthy structures.",
    ({ "road" }) : "The road is a heavily packed sand path that leads from "
                   "the North Gate to the South Gate.",
    ({ "oasis", "bazaar" }) : "The Oasis and Bazaar lie to the west and east, respectively.",
    ]) );
  SetItemAdjectives( ([
    "building" : ({ "small" }),
    "road" : ({ "gate" }),
    "oasis" : ({ "yozrath" }),
    ]) );
  SetInventory( ([
    YOZRATH_NPC "equipper" : 1,
    YOZRATH_NPC "free_armourer" : 1,
    YOZRATH_NPC "guard"    : 2,
    ]) );
  SetSmell("Interesting smells waft from the east.");
  SetListen("Even from this distance, the noise from the bazaar is a hum.");                                                       
}
