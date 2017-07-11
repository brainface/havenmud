/*  The cash room */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  object cash;
  room::create();
  SetClimate("indoors");
  SetShort("the southern part of the cave");
  SetObviousExits("north");
  SetExits( ([
     "north" : STRYKE_LAIR + "2_i",
      ]) );
  SetProperty("login", STRYKE_LAIR + "2_i");
  SetProperty("no teleport", 1);
  SetLong("This large room appears to have been the room where Stryke "
          "hoarded her treasures.  To the north is the cave that served as "
          "her lair.");
  SetSmell( ([
     "default" : "The musty smell of forgotten treasures clouds the room.",
     ]) );
/*
  cash = new("/lib/pile");
*/
  cash = new("/lib/items/pile");
  cash->SetPile("imperials", random(50000000) + 500000);
  cash->eventMove(this_object());
  }
