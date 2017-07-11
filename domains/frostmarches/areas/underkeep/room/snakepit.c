//
// Above a pit
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a pit");
  SetLong("The passage from the south changes abruptly here, "
    "ending in a ledge above a large pit, about twenty "
    "feet in diameter. This looks like some kind of "
    "lair for whatever foul creature has made its abode "
    "in these depths. The bottom of the pit is shrouded in "
    "darkness to thick to penetrate."),
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"walls", "moisture"}) :
      "The walls are sticky to the touch, and are saturated by some "
      "kind of slimy excretion.",
    "ceiling" :
      "The ceiling is only 5 feet high here, and worn down to the "
      "texture of glass.",
    "ledge" :
       "The ledge is fairly narrow and ends abruptly. It leads"
       " back to the south and down into the pit.",
     ({"lair", "depths", "pit"}) :
       "Nothing can be made out at the bottom. The darkness is too "
       "complete.",
    ]) );
  SetItemAdjectives( ([
    "pit" : ({"large","of darkness"}),
    ]) );
  SetSmell( ([
    "default" :
      "The stench of this place is beyond description.",
    ({"moisture" , "walls"}) :
      "The moisture covering the walls smells like rancid milk.",
    ]) );
  SetListen( ([
    "default" :
      "The sound of snakes is very loud here and appears "
      "to be coming from that pit.",
    "pit" : "There is a lot of hissing coming from down there.",
    ]) );
  SetExits( ([
    "down" : RNQ_RM + "snlair.c",
    "south" : RNQ_RM + "ncor3.c",
    ]) );
}
