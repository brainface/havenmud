/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("at the Base of an Emerald Tower");
  SetClimate("temperate");

  SetNightLight(30);
  
  SetLong("The road curves here to the base of a fallen tower, seemingly "
    "carved all of emerald. Some trick of the light must have made it seem "
    "to be standing still, from a distance. An impassible wall of rubble "
    "blocks the way further to the north. To the west, a shining rose-colored "
    "cathedral stands.");

  SetItems( ([
    "tower" : "Whatever doors once barred entry here have long since rotten "
      "away, leaving a gaping square frame standing alone, surrounded by the "
      "rubble of a toppled tower.",
    "emerald" : "something about no there's not a fortune of emeralds here." 
      
      
  ]) );

  SetExits( ([
    "southwest" : ROOM "/upperSE",
  ]) );

  SetEnters( ([
    "tower" : ROOM "/mage_tower0",
  ]) ); 
  
  SetSmell( ([
    "default"  : "It smells of mold and rotten meat.",
  ]) );

  SetListen( ([
    "default"  : "Chittering and chirping insects chatter somewhere "
      "just out of sight.",
  ]) );

  SetInventory( ([
    //NPC "/koboldm"  : 2
  ]) );

}

