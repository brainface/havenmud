#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;
#define STRYKE "/domains/havenwood/areas/stryke/connect"

static void create() {
  room::create();
  SetShort("a clearing in the woods");
  SetLong("The trees are thin here and seem to be more scattered. "
    "There is a small trail that leads to the north and a glen is "
    "faintly visible to the northwest. To the east lies what seems "
    "to be another clearing or glen. There are several different types "
    "of oddly shaped leaves that scatter the ground. A large mist "
   "swirls here and seems rather ominous.");
  SetItems( ([
    ({"wall of trees","wall","trees","tree"}) :
      "The wall of trees to the east does not seem so impassible "
      "upon further inspection.  Oddly, most creatures could even "
      "attempt to go east if they wanted.",
    ({"leaves", "leaf"}) : 
      "The leaves lie scattered about, as if they had been disturbed "
      "by more traffic than could have come this way alone.",
    ({"small animal trail","small trail","animal trail","trail","path" }) : 
      "An animal trail leads north of here, and westward, the "
      "trail that goes to the overland road stretches.",
    ({"glen"}) :
      "There is a small glen to the northwest.",
     ({ "mist", "large mist", "ominous mist", "mist of chaos" }) :
           "The mist seems to lead somewhere.",
     ]) );
  SetExits( ([
     "northwest" : STRYKE,
    "east" : "/domains/havenwood/areas/wood/rooms/birth",
    "north" : "/domains/havenwood/areas/wood/rooms/trail1",
     "west" : HWD_ROOM + "/wood2",
      ]) );
  SetEnters( ([
    "mist" : "/domains/planes/virtual/forest/0,0",
    ]) );
  }
