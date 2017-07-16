/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: s1.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("along the southern side of the pyramid");
  SetLong("The area here isn't as dark as the area to the east. "
          "The petroglyphics continue their way, carved in the "
          "stone-made walls. Here, a huge chasm has caused the "
          "disappearance of the floor to the north. The tiled "
          "floor goes west to the pyramid's entrance, and east "
          "into darkness."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "The petroglyphics "
                                                   "in this area, are "
                                                   "representing a great "
                                                   "war.",
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
                       "walls" : ({"stone","dark","stone-made"}),
                       "chasm" : ({"dark","bottomless","deep"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "petroglyphics" : ({"carved"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/entrance",
              "east" : P_ROOM + "/inter_s2",
          ]) );
  SetInventory ( ([ P_NPC + "/gihan" : 1 ]) );
  SetSmell( ([ "default" : "A strong putrid odor is present."]) ); 
  SetListen( ([ "default" : "Sounds of whimpering and moaning "
                            "can be heard." ]) ); 
}
/*                                                                   */