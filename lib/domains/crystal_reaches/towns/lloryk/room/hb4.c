#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("an intersection along Heroes Lane");
  SetExits( ([
     "east"  : LLORYK + "room/uh6",
     "west"  : LLORYK + "room/hb3",
     "south" : LLORYK + "room/sg2",
     "north" : LLORYK + "room/farm1",
     ]) );
  SetLong("Heroes Lane meets here with a small path that heads off to "
          "the south.  Far to the west, the road leads to the feared "
          "Gwonish swamp, a land of evil bearing an ancient curse. "
          "To the east, the road curves north after meeting up in front "
          "of the Eclat Temple, center of spiritual life in Lloryk. "
          "All around, the rolling hillside makes for fine farming."
          );
  SetListen( ([
    "default" : "To the west, the sounds of farm life drift on the winds.",
    ]) );
  SetSmell( ([
    "default" : "Manure and wet soil smell almost nice but quite horrible.",
    ]) );
  SetItems( ([
    ({ "hill", "hills", "hillside" }) : "The rolling hills of Lloryk "
                                        "stretch out in all directions.",
    ({ "temple" }) : "The Eclat Temple is a small wooden building that seems "
                     "more like a meeting hall than a temple.",
    ]) );
  SetItemAdjectives( ([
    "hill"   : ({ "rolling", }),
    "temple" : ({ "troist", "wooden", "small" }),
    ]) );
  SetInventory( ([
    LLORYK + "obj/signhb4" : 1,
  ]) );
}

