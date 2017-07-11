/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: entrance.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("the entrance to a dark pyramid");
  SetLong("This is an obscure place that seems to be the "
          "entrance to the pyramid. "
          "In the dark stone walls, some sort of "
          "old petroglyphics are perfectly carved, "
          "resembling a very ancient form of writing. "
          "To the northeast, the ground disappears in a "
          "bottomless chasm. The floor extends to the north "
          "and to the east. The exit of the pyramid is to the south."
         );
  SetItems( ([ ({"petroglyphics","petroglyphic"}) : "The petroglyphics "
                                                    "depict the death of "
                                                    "someone important.",
               ({"pyramid","place"}) : (: GetLong :),
               ({"walls","wall"}) : "The grey walls seem to be made "
                                    "out of perfectly cut dark stone.",
               ({"stone"}) : "A very dark type of stone forms the "
                             "wall and floor.",
               ({"chasm","pit"}) : "A dark bottomless pit exists to "
                                   "the east.",
               ({"ground","floor"}) : "The floor is made up of stones "
                                      "tiled together."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"grey","stone","dark"}),
                       "pyramid" : ({"dark","obscure"}),
                       "petroglyphics" : ({"old","carved"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "chasm" : ({"bottomless","dark"}),
                       "floor" : ({"tiled"})
                   ]) );
  SetExits( ([
              "north" : P_ROOM + "/w1",
              "east" : P_ROOM + "/s1",
              "out" : "/domains/baria/virtual/jungle/-5,3"
           ]) );
  SetSmell(([ "default" : "A foul odor comes from the chasm.",
              "chasm" : "The smell from the chasm is of burnt "
                        "and rotten flesh." ]));
}			
