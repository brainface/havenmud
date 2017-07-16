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
  SetLong(
    "The passage wriggles from side to side, limiting vision to just"
    " twenty feet or so. The walls are curiously uniform, and it would"
    " be quite easy to get turned around here and end up going back the"
    " same way. The walls and ceiling have been scraped smooth by"
    " some creature or other, and slime drips down onto the floor,"
    " making the ground underfoot treacherously slippery.");
  SetClimate("underground");
  SetAmbientLight(1);
  SetItems( ([
    ({"walls", "moisture"}) :
      "The walls are sticky to the touch, and are saturated by "
      "some kind of slimy excretion.",
    ({"slime","excretion"}) : "The slime is viscous and slightly warm.",
    ("ceiling") :
      "The ceiling is only 5 feet high here, and worn "
      "down to the texture of glass.",
    "ground" : "The ground is covered with the same slimy excretion"
      " as the walls and ceiling.",
    ]) );
  SetItemAdjectives( ([
    "ground" : "slippery",
    "walls" : ({"smooth","uniform"}),
    "ceiling" : "smooth",
    "excretion" : ({"warm","viscous","slimy"}),
    ]) );
  SetSmell( ([
    "default" : 
    "The stench of this place is beyond description.",
    ({"moisture" , "walls"}) : 
      "The moisture covering the walls smells like the armpit of "
      "the devil himself",
    ]) );
  SetListen( ([
    "default" :
       "There are sounds of slithering coming from "
       "somewhere to the north.",
    ]) );
  SetInventory( ([
    RNQ_NPC + "icklesnake" : 1,
    ]) );
  SetExits( ([
    "north" : RNQ_RM + "ncor3.c",
    "south" : RNQ_RM + "ncor1.c",
    ]) );
}
