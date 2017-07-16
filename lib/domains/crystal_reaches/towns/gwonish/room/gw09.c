// updated by torak 10/27/12
// items, items adjectives
// bamboo enclosement enter

#include <lib.h>
#include <domains.h>
#include "../gwonish.h"
inherit LIB_ROOM;

static void create() {
  ::create(); 
  SetClimate("sub-tropical");
  SetShort("a curve in the swamp path");
  SetLong("A small stream of rancid water heads off to the northwest from "
    "here, making a small trail that can be followed. Further to the "
    "east, the trees seem to open up slightly, forming into a path "
    "leading into the swamp. To the south, the decay seems fairly "
    "thick, making the smell of death waft in richly. To the north, "
    "a bamboo enclosement has been erected.");
  SetItems( ([
    ({ "stream", "water", "froth" }) : 
        "The stream is foul looking with a foamy froth drifting along its path.",
    ({ "trail", "path" }) : "The trail cuts its way through the swamp.",
    ({ "trees" }) : "The trees of the swamp grow twisted and foul.",
    ({ "decay", "swamp", "foliage", "fauna" }) : 
        "Rotting foliage and fauna are slowly digested by the swamp.",
    ({ "enclosement", "bamboo" }) : "The bamboo enclosement looks inviting.",
    ]) );
  SetItemAdjectives( ([
    "stream" : ({ "small", "rancid", "foamy" }),
    "trail" : ({ "small" }),
    "enclosement" : ({ "bamboo" }),
    ]) );
  SetSmell( ([
    "default" : "The stench of decay is stong here.",
    ]) );
  SetListen( ([
    "default" : "Sounds of life come from the northwest.",
    ]) );
  SetInventory( ([
    GWONISH_NPC "guard" : 1,
    ]) );
  SetExits( ([
    "east"      : GWONISH_ROOM "gw10",
    "south"     : GWONISH_ROOM "gw05",
    "northwest" : CRYSTAL_REACHES_AREAS "gwonish/room/swamp18",
    ]) );
  SetEnters( ([
    "enclosement" : GWONISH_ROOM "enclosement",
    ]) );
  }
