//
// at the base of a tower
// by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
  inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("base of a crumbling tower");
  SetLong(
    "From here, an obelisk of masonry and rotting timber forces"
    " its way up through the solid rock and out of sight. A twisting"
    " staircase winds its way precariously up into the darkness above."
    " The ceiling is totally of bare stone now, and the floor below is"
    " littered with black and white tiles. There was another passage"
    " turning to the south, but this has become blocked off by rubble.");  
  SetClimate("underground");
  SetAmbientLight(1);
  SetExits( ([
    "east" : RNQ_RM + "wcor2.c",
    "up" : RNQ_RM + "rubble1.c",
    ]) );
  SetItems( ([
    "floor" : "The floor is littered with little black and white tiles.",
    ({"stairs","staircase","steps"}) :
      "The stairs at first glance look dangerous, but will probably hold.",
    ({"rock","tower","obelisk"}) :
      "The tower appears to have forced its way upwards through the "
      "rock, yet the seal between them looks artificially tight.",
    ({"tiles"}) :
      "The ceiling tiles lying on the floor are of black and white marble.",
    ({"rubble","passage"}) :
      "Loose shale and dirt block the passage to the south.",
    "ceiling" : "The ceiling is like a threadbare carpet, with a few tiles"
      " grimly clinging on to an otherwise bare ceiling.",
    "shale" :
      "This consists of small chunks of rock that fill the passage south.",
    "dirt" : "It's brown. When mixed with water, it makes mud.",
    ]) );
  SetItemAdjectives( ([
    "tiles" : ({"ceiling","little","white","black","marble"}),
    "passage" : "south", 
    "ceiling" : "bare",
    "stairs" : "twisting",
   ]) );
  SetListen( ([
    "default" :
      "Silence reigns.",
    ]) );
  SetInventory( ([
    ]) );
}
