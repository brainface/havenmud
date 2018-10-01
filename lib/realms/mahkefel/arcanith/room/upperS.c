/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("atop the upper tier near a staircase.");
  SetClimate("temperate");

  SetNightLight(30);
  SetExits( ([
    "northeast" : ROOM "/upperE",
    //"south" : ROOM "/ruins8",
    "south" : ROOM "/staircase",
    //"northwest" ROOM "/upperNW",
  ]) );

  SetLong("You've made it through the vines! Good job, you!.");
  /*SetDayLong("The destruction of the ruins is obvious inside the wall.  "
             "Weeds grow between the stones of the road.  Buildings crumble "
             "into rubble.  A road follows around the inside of the wall.  "
             "The second road leads deeper into the ruins.  The crossroad "
             "is bathed in the silver light of the wall.");

  SetNightLong("Eerie shadows dance among the decaying buildings.  The "
               "silver light from the wall illuminates the crossroad.  One "
               "road leads along the wall and is bathed in its light.  The "
               "second leads deeper into the ruins.  Both are being overrun "
               "by weeds.");
  */
  SetItems( ([
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

