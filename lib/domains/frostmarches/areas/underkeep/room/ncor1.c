//
// a corridor
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
 inherit LIB_ROOM;

static void create () {
  room::create();
  SetShort("a serpentine corridor");
  SetLong("The passage winds in a north-south direction, "
    "twisting from side to side like a serpent. The "
    "ceiling is low here, and smoothed as if by the "
    "passage of some giant worm. The walls glisten with "
    "moisture, and a sense of forboding hangs in the fetid"
    " air.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    "corridor" : (:GetLong:),
    ({"wall","walls", "moisture"}) : 
      "The walls are sticky to the touch, and are saturated by "
      "some kind of slimy excretion.",
    ("ceiling") :
      "The ceiling is only 5 feet high here, and worn "
      "down to the texture of glass.",
    ]) );
  SetItemAdjectives( ([
    "walls" : ({"glistening","sticky"}),
    "ceiling" : "smooth",
    ]) );
  SetSmell( ([
    "default" : 
    "The stench of this place is beyond description.",
    ({"moisture" , "walls"}) : 
      "The moisture covering the walls smells like the armpit of "
      "a corpse left in the sun to rot for a week.",
    ]) );
  SetListen( ([
    "default" :
       "There are faint sounds of slithering coming from "
       "somewhere to the north.",
    ]) );
  SetExits( ([
    "north" : RNQ_RM + "ncor2.c",
    "south" : RNQ_RM + "rubble2.c",
    ]) );
}
