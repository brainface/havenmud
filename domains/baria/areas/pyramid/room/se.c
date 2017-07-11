/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: se.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("the southeastern corner of the pyramid");
  SetLong("A single small torch hanging from the eastern "
          "wall gives out more light than it normally should. "
          "Both walls are all covered with petroglyphics. And "
          "to the northwest, a dark and deep chasm opens up on "
          "the ground."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "The people depicted "
                                                   "a while ago seem to "
                                                   "be creating something.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone."
                                   "They're all covered with petroglyphics.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the northwest.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"torch"}) : "This small torch gives out a large "
                            "amount of light."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","deep"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "torch" : ({"small"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/s3",
              "north" : P_ROOM + "/e1",
          ]) );
  SetSmell( ([ "default" : "There's a strange odor in the air"]) ); 
  SetListen( ([ "default" : "Screams of pain are haunting the area." ]) ); 
  SetInventory( ([ P_NPC + "/bat" : 5 ]) );
}
/*                                                                   */