/* Wall road */

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort ("a wide staircase through the inner walls");
  SetClimate("temperate");

  SetNightLight(30);
  SetExits( ([
    "north" : ROOM "/upperS",
    //"south" : ROOM "/ruins8",
    "south" : "/domains/frostmarches/towns/arcanith/room/ruins8",
  ]) );

  SetLong("A wide staircase leading to the upper tier. Maybe some angry "
    "creeper vines that attack? Newbies should be able to walk through "
    "unmolested, though. Maybe they should just look real bad.");
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

