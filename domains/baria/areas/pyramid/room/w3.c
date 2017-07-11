/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: w3.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("along the western side of the pyramid");
  SetLong("There's a hole in the wall here, but it is obstructed "
          "by a pile of large rocks. The huge dark chasm to the east "
          "finally comes to an end here. To the south and to the "
          "north, where a dim light seems to shimmer, the road "
          "continues."
	    );
  SetItems( ([
              ({"wall"}) : "The wall has a big hole in the middle.",
              ({"chasm","pit"}) : "A dark bottomless pit exists to the east.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"rocks","rock"}) : "Some irregular rocks are piled together.",
              ({"light"}) : "A dim light is north of here.",
              ({"road"}) : "The road to could follow is either "
                           "north or south.",
              ({"hole"}) : "A hole made in the wall. It is covered by a "
                           "pile of rocks.",
              ({"glow"}) : "A small glow can be seen among the rocks.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor."
           ]) );
  SetItemAdjectives( ([
                       "wall" : ({"west","stone"}),
                       "chasm" : ({"dark","huge","bottomless"}),
                       "floor" : ({"tiled"}),
                       "rocks" : ({"large","irregular","pile of","piled"}),
                       "light" : ({"dim"}),
                       "hole" : ({"obstructed"}),
                       "stone" : ({"dark","grey","tiled"})
                    ]) );
  SetExits( ([ 
              "north" : P_ROOM + "/nw",
              "south" : P_ROOM + "/inter_w2",
          ]) );
  SetSmell( ([ "default" : "Unmentionable odors are in the air." ]) );
  SetListen( ([ "default" : "Sad moans can be heard in here." ]) );
}
/*                                                                   */
