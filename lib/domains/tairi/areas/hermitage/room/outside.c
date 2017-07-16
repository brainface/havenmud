#include <lib.h>
#include "../herm.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("outside a suspicious looking hermitage");
  SetLong("Here at the base of the mountain resides"
          " a small and suspicious looking cottage."
          " The shoddy craftsmanship of the cottage"
          " combined with the decay of the wood"
          " makes one assume this hermitage is"
          " abandoned or inhabited by an extremely"
          " old hermit.");
  SetSmell( ([
          "default" : "A soft spicy odor eminates from the cottage.",
       ]) );
  SetItems( ([
     ({ "cottage", "hermitage", "building", "home" }) : 
         "This small cottage is shoddily made, with decaying wood. "
         "It appears abandoned.",
        ]) );
  SetItemAdjectives( ([
     "cottage" : ({ "small", "abandoned", "shoddy", "suspicious" }),
     ]) );
  SetExits( ([
           "north" : "/domains/tairi/areas/mountain/room/mtn1",
        ]) );
  SetEnters( ([
           "cottage" : HERM_ROOM "herm1",
           "hermitage" : HERM_ROOM "herm1",
        ]) );
}
