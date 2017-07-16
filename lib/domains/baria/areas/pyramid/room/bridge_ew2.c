/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: bridge_ew2.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("In a bridge over the chasm");
  SetLong("This is part of a bridge standing above the chasm "
          "that can be seen to the north and south. The bridge "
          "is made of the same dark stone that forms all of the "
          "walls and the floor of the pyramid. The bridge goes "
          "west, and east to the center of the pyramid."
	    );
  SetItems( ([
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the south and to the north.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"bridge"}) : "This bridge goes to the east and to the "
                             "west.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor.",
           ]) );
  SetItemAdjectives( ([
                       "chasm" : ({"dark","bottomless","ominous"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"grey","tiled","dark"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/inter_w2",
              "east" : P_ROOM + "/center"
          ]) );
  SetSmell( ([ "default" : "This place stinks." ]) );
  SetListen( ([ "default" : "Moans can be heard fading into silence." ]) );
}
/*                                                                   */
