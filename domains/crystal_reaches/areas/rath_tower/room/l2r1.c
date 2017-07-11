#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("inside the tower");
  SetObviousExits("east, west, down");
  SetExits( ([
    "east"  : TOWER_R + "/l2e1",
    "down"  : TOWER_R + "/entrance",
    ]) );
  AddExit("west", TOWER_R + "/l2w1", (: PreExit :) );
  SetInventory( ([
    TOWER_N + "/eguard" : 2,
    ]) );
  SetAmbientLight(40);
  SetLong("The second floor of the tower is much like the first, with "
         "the key differance being one of windows. The windows look "
         "out over the world in all its majestic splendor, yet cast "
         "a pall of wintery cold onto the scene. There are exits to "
         "the east and west, and a staircase leading back down.");
  SetSmell( ([
    "default" : "The overpowering smell of dust clogs the air.",
    ]) );
  SetListen( ([
    "default" : "A brief echo of a screaming human seems to not quite be heard.",
    ]) );
  SetItems( ([
     ({ "stairs", "staircase" }) : "The stairs lead down into the entrance.",
     ]) );
}

int PreExit(string dir) {
    object *guards;
  if (immortalp(this_player())) { return 1; }
  if (sizeof(guards = filter(all_inventory(), (: $1->id("elite guard") && living($1) :) ))) {
        object guard = guards[0];
        guard->eventForce("speak Where do you think you are going?");
        guard->eventForce("emote shakes his head.");
        guard->eventForce("laugh sadistically");
        return 0;
       }
     return 1;
}
