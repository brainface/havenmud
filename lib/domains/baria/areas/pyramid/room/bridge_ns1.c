/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: bridge_ns1.c
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
  SetLong("This bridge crosses the pyramid from north to south "
          "passing by its center. This area is dimly illuminated "
          "with the light coming from the north. There's a huge "
          "chasm below the bridge, it can be seen to the east "
          "and west. Following to the south, the center of the "
          "pyramid lies ahead. The other way goes to the north."
	    );
  SetItems( ([
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the west and to the east.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"bridge"}) : "This bridge goes to "
                             "the south and to the north.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor.",
              ({"pyramid"}) : "You're inside of it!"
           ]) );
  SetItemAdjectives( ([
                       "chasm" : ({"dark","bottomless","huge"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"grey","tiled","dark"})
                    ]) );
  SetExits( ([ 
              "south" : P_ROOM + "/center",
              "north" : P_ROOM + "/inter_n2"
          ]) );
  SetSmell( ([ "default" : "The smell of something decomposing "
                           "is strong." ]) );
  SetListen( ([ "default" : "The sounds of someonw whining are "
                            "present." ]) );
}
/*                                                                   */
