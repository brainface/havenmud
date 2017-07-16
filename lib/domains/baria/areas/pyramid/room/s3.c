/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: s3.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(5);
  SetShort("the southern side of the pyramid");
  SetLong("This part of the pyramid is the darkest one, and besides "
          "the chasm to the north helps the atmosphere to be even "
          "darker. The carved petroglyphics can barely be seen "
          "because they are all heavily covered with dust. The path "
          "goes east and west."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "Several animals "
                                                   "and people are "
                                                   "depicted living "
                                                   "happily.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the north",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"pyramid"}) : "You're inside of it!"
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","deep"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "petroglyphics" : ({"carved"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/inter_s2",
              "east" : P_ROOM + "/se",
          ]) );
  SetSmell( ([ "default" : "An unknown odor fills the area."]) ); 
  SetListen( ([ "default" : "There's a faint sound of rattling "
                            "chains." ]) ); 
}
/*                                                                   */
