


#include <lib.h>
#include "../ninja.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a small quite room within the tower");
  SetExits( ([
    "east" : N_ROOM "tower1",
    ]) );
  SetClimate("indoors");
  SetLong("Everything here is neatly ordered. A small inventory"
          " has been presented along the wall in picture form"
          " and everything else in the room compliments it"
          " very nicely. There is a reed rug on the floor"
          " which appears to be well taken care of.");
  SetItems( ([
     ({ "inventory", "goods", "picture" , "pictures"}) :
        "The pictures show various goods for that are for sale here.",
     ({ "rug", "reed rug" }) :
       "This reed rug looks to be very well taken care of"
       " it shows minor signs of wear but otherwise looks"
       " brand new.",   
    ]) );
  SetAmbientLight(40);
  SetInventory( ([
     N_NPC "shopkeep" : 1,
  ]) );
  SetSmell( ([
    "default" : "The smell of leather and steel fills the air.",
    ]) );
  SetListen( ([
    "default" : "The room is quiet and peaceful.",
    ]) );
}
