/*  Level #1 - Cave #1 - Section #3  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a small cavern");

  SetLong("This is the end of the cavern.  It splits off in two directions.  "
          "The first tunnel to the northeast and the second to the northwest. "
          " Neither reveals anything to the outside observer.  The rock "
          "formations all about you give a the cavern a forest-like quality.");

  SetSmell( ([
    "default"  :  "The smell of guano and limestone finds it's way into your "
                  "nose."
  ]) );

  SetListen( ([
    "default"  :  "High pitched voices and flapping of leathery wings can be "
                  "heard to the south."
  ]) );

  SetExits( ([
    "northwest"  :  ROOMLV1 + "/downtolv2",
    "south"      :  ROOMLV1 + "/cave1b"
  ]) );
  AddExit("northeast", ROOMLV1 + "/kobold1", (: PreExit :)),
  SetObviousExits("northeast, northwest, south");

  SetItems( ([
    ({ "small cavern", "cavern" })  :  (: GetLong :),
    ({ "tunnels", "tunnel", "first tunnel", "second tunnel" })  :
       "Each tunnel soon twists out of sight and neither gives the slightest "
       "hint as to what may be beyond.",
    ({ "rock formations", "rock formation" })  :
       "The rock formations gives the cavern an ancient, yet ageless quality. "
       " Some of the stalactites and stalagmites are joined together into "
       "great columns of limestone.  This gives the cavern a certain "
       "forest-like quality.",
  ]) );

SetInventory( ([ NPCS + "/bat" : 1, ]) );
}

int PreExit(string dir) {
  if(this_player()->GetProperty("Telgos")) {
    return 0;
  }  else {
    return 1;
  }
}