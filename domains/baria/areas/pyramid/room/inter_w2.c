/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: inter_w2.c
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
  SetLong("The road intersects here with a bridge to "
          "the east that seems to run to the center "
          "of the pyramid. The wall is covered with white "
          "and grey cobwebs, hiding the carved "
          "petroglyphics. The path continues to the "
          "north and south, east to the bridge. "
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "You can't get "
                                                   "to look at them "
                                                   "very well because "
                                                   "of the cobwebs.",
              ({"wall"}) : "The wall is all covered by cobwebs.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the southeast and to the northeast "
                                  "passing below the bridge.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"cobwebs","cobweb"}) : "A large patch of cobwebs that "
                                       "seem to be inhabited.",
              ({"bridge"}) : "A bridge stands to the east, leading "
                             "further in that way.",
              ({"path"}) : "It leads to the south and to the north. "
                           "East into the bridge.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor.",
           ]) );
  SetItemAdjectives( ([
                       "petroglyphics" : ({"old","carved"}),
                       "wall" : ({"west","stone"}),
                       "chasm" : ({"dark","bottomless","ominous"}),
                       "floor" : ({"tiled"}),
                       "cobweb" : ({"white","grey","white and grey","large"}),
                       "stone" : ({"grey","tiled","dark"})
                    ]) );
  SetExits( ([ 
              "north" : P_ROOM + "/w3",
              "south" : P_ROOM + "/w1",
              "east" : P_ROOM + "/bridge_ew2"
          ]) );
  SetInventory ( ([ P_NPC + "/spider" : 3 ]) );
  SetSmell( ([ "default" : "Unbearable odor fills the place." ]) );
  SetListen( ([ "default" : "The whimpers have become louder.",
                "chasm" : "Whimpering and crying can be heard." ]) );
}
/*                                                                   */