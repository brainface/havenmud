/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: bridge_ns2.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(5);
  SetShort("in a bridge over the chasm");
  SetLong("This intersecting bridge passes by the center of the "
          "pyramid from north to south. This part of the bridge "
          "is so dark it's even difficult to tell the difference "
          "between the limits of the bridge and the chasm that can "
          "be seen east and west. To the north is the center of the "
          "pyramid, the other way leads south."
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
              "south" : P_ROOM + "/inter_s2",
              "north" : P_ROOM + "/center"
          ]) );
  SetSmell( ([ "default" : "The terrible smell of death is very "
                           "strong. " ]) );
  SetListen( ([ "default" : "The loud screams are horrible." ]) );
}
/*                                                                   */