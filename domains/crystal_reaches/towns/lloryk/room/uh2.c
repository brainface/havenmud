#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("along a road through the Shire");
  SetExits( ([
     "north" : LLORYK + "room/uh1",
     "south" : LLORYK + "room/uh3",
     ]) );
  SetLong("The path continues to the north and south from here. "
          "Off to the south, the path leads to the heart of Shire, "
          "where the main buildings of the village lie. Rolling hills "
          "surround the town to the west. To the east, the towering "
          "of the Crystal Reaches rise against the sky.");
  SetListen( ([
     "default" : "The bleating of sheep and mooing of cows comes "
                 "from the west.",
     ]) );
  SetSmell( ([
     "default" : "The smells of farmland are a strange mix of the pleasant "
                 "and unpleasant.",
     ]) );  
    SetItems( ([
    ({ "hill", "hills", "hillside" }) : "The rolling hills of Lloryk "
                                        "stretch out in all directions.",
    ({ "peak", "peaks", "mountain", "reaches" }) : "The Crystal Reaches "
            "are the longest and most majestic of the mountain ranges of "
            "Kailie.",
    ]) );
  SetItemAdjectives( ([
    "hill"   : ({ "rolling", }),
    "reaches": ({ "crystal", }),
    ]) );          
}
