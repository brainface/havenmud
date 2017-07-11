/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: inter_s2.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(5);
  SetShort("the southern intersection with a bridge");
  SetLong("The obscure road is intersecting with a bridge going "
          "north. The area here looks as if it was eternally "
          "covered by the darkest of all nights. "
          "The walls are now covered by many petroglyphics, "
          "maybe something important is going on. "
          "The chasm can be "
          "seen to the northwest and passes below the bridge, "
          "continuing to the northeast. The road extends west, "
          "east, and north into the bridge."
         );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "They represent "
                                                   "two important "
                                                   "people "
                                                   "arguing about "
                                                   "something.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the northeast and northwest.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"bridge"}) : "A stone bridge goes north of here.",
              ({"area"}) : (: GetLong :)
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","deep"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "petroglyphics" : ({"carved"}),
                       "bridge" : ({"stone"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/s1",
              "east" : P_ROOM + "/s3",
              "north" : P_ROOM + "/bridge_ns2"
          ]) );
  SetSmell( ([ "default" : "An awful smell can be noticed in this "
                           "area."]) ); 
  SetListen( ([ "default" : "Some noises to the north can be heard." ]) ); 
}
/*                                                                   */
