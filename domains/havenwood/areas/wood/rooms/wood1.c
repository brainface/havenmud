
#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;   
#define STRYKE "/domains/havenwood/areas/stryke/connect"
int PreEnter(string dir);

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
  //AddEnter("mist", "/domains/planes/virtual/forest/0,0", (: PreEnter :) );
  SetInventory( ([
    HWD_OBJ "/wood1sign" : 1,
  ]) );
}
/*
int PreEnter(string dir)
{
  if (this_player()->GetLevel() < 50  && userp(this_player()) && !creatorp(this_player())) {
    send_messages("",
      "A primal, irresistable %^GREEN%^fear%^RESET%^ grips you as you try to push the mists, and you turn aside.",
      "The mists %^BOLD%^GREEN%^swirl angrily%^RESET%^ as $agent_name tries to enter.",
      this_player(), 0, environment(this_player()) );
    this_player()->eventPrint("You must be level 50 or more to enter the mists.");
    return 0;
  }
  return 1;
}
*/
