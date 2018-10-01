#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "out" : "level2hub",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(60);
  SetShort("inside a spotless bank");
  SetLong("The Capital Bank of Floeholm's Underland branch is a small "
          "rectangular room carved out of solid basalt stone. The teller "
          "window is small and heavily barred at the counter. The floor "
          "is a checkerboard of basalt and marble tiles. The walls reflect "
          "the torchlight. The ceiling is supported by large pillars at each "
          "corner of the room." 
          );
  SetItems( ([
    ({ "walls", "wall" }) : 
          "The walls are carved out of the rock of the mountain above. They "
          "are basalt black and brightly polished. The torchlight flickers "
          "brightly off the polished walls.",
    ({ "torches", "sconces", "sconce" }) : 
          "The torches are hanging in iron ring sconces set into each wall.",
    ({ "pillar", "pillars", "bands", "brass" }) :
          "The pillars are brightly polished marble of white and grey giving "
          "a stark contrast to the basalt walls. Each pillar is rounded at the "
          "bottom, middle and top by large brass bands. The middle band holds a "
          "triplet of torches.",
    ({ "ceiling", "buttresses", "buttress" }) :
          "The ceiling is buttressed with large iron bands that anchor "
          "into the pillars at each corner of the room.",
    ({ "counter", "slate", "window", "bars" }) :
          "The teller window has been heavily reinforced with large iron bars "
          "that are set into the counter itself. The counter between the "
          "windows is a solid plate of slate. The majority of the "
          "surface is rough, except in areas of high traffic that have "
          "been worn to a dull polish by years of use.",
    ({ "floor", "tiles", "tile", "rock", "down" }) :
          "The floor is perfectly clean and the floor has been worn to a "
          "bright polish from years of traffic, while the basalt "
          "sections are still rough near the walls. The tiles are all marble " 
          "of the finest quality sunken into the basalt floor that was cut to "
          "accept the tiles. The basalt sections of the floor are the natural "
          "rock of the mountain.", 
          ]) );
  SetInventory( ([
    UNDER_NPC "banker" : 1,
    ]) );    
}
