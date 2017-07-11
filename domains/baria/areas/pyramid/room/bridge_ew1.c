//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: bridge_ew1.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("in a bridge over the chasm");
  SetLong("This is the eastern part of the bridge going east-west "
          "across the center of the pyramid. Below the bridge, "
          "there's a dark and bottomless chasm that can be seen "
          "to the north and south. The bridge here looks very old "
          "and gives the idea it could fall apart any moment now. "
          "The bridge goes east, and west to the center of the "
          "pyramid."
	    );
  SetItems( ([
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the south and to the north.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"bridge"}) : "This bridge looks very old. It goes to "
                             "the east and to the west.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor.",
              ({"pyramid"}) : "You're inside of it!"
           ]) );
  SetItemAdjectives( ([
                       "chasm" : ({"dark","bottomless","and"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"grey","tiled","dark"}),
                       "bridge" : ({"old"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/center",
              "east" : P_ROOM + "/inter_e2"
          ]) );
  SetSmell( ([ "default" : "There's a foul smell in here." ]) );
  SetListen( ([ "default" : "A woman crying can be heard from "
                            "somewhere." ]) );
}
/*                                                                   */
