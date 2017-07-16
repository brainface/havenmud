// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <domains.h>
#include "../karak.h"
inherit LIB_ROOM;
int DomainCheck();

static void create() {
  room::create();
  SetShort("the Karak Road");
  SetLong(
    "A dirt road leads south from here, towards the cluster of buildings "
    "which comprise the town of Karak. While distant, it can be seen that "
    "the majority of these buildings are built of simple wood. Closer to "
    "this location is a pair of buildings formed of stone, which sit to "
    "either side of the road. At the very bottom edge of the horizon is a "
    "rim of blue. North of here the dirt road connects to the main road "
    "from Haven to the Crystal Reaches."
    );
  SetItems( ([
    ({ "road", "path" }) : "This dirt road leads south to the town of "
    "Karak. To the north it connects to the main road from Haven to the "
    "Crystal Reaches.",
    ({ "buildings", "building" }) : "A pair of stone buildings sit slightly "
    "south of here. Further past them are a cluster of wooden buildings "
    "which form the main part of the town of Karak.",
    ({ "horizon", "blue", "ocean" }) : "A narrow rim of blue lies upon "
    "the horizon, suggesting the ocean is far to the south.",
  ]) );
  SetItemAdjectives( ([
    "road" : ({ "dirt" }),
    "buildings" : ({ "stone", "pair", "of", "wooden", "south", "simple",
      "cluster", "main", "town" }),
    "horizon" : ({ "very", "bottom", "edge", "rim", "of", "narrow" }),
  ]) );
  SetSmell( ([
    "default" : "Dust from the road flavors the air.",
  ]) );
  SetListen( ([
    "default" : "Occasional sounds drift in from the main road to the north."
  ]) );
  SetExits( ([
//    "north" : "/realms/laoise/home/other_room",
    "south" : KARAK_ROOM + "rd2",
  ]) );
  AddExit("north", SOUTHERN_COAST_VIRTUAL "havenroad/-36,0", (: DomainCheck :) );
}

int DomainCheck() {
  if (!OPEN_SOUTHERN_COAST)
    this_player()->eventPrint("Further travel in that direction is not "
    "allowed right now.");
  return OPEN_SOUTHERN_COAST;  
}