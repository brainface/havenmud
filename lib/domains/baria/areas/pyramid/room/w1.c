/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: w1.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("just north of the pyramid's entrance");
  SetLong("The ambient here is darker and the air denser. "
          "The petroglyphics "
          "continue on the wall to the west just as if they "
          "were telling a story. The pitch black chasm on the east "
          "looks like it could actually contain something deep "
          "inside. The tiled floor continues to the north and to "
          "the south is the entrance to the pyramid."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "These petroglyphics "
                                                   "keep telling the "
                                                   "story after the death "
                                                   "of the god. The war "
                                                   "seems to have ended.",
              ({"area"}) : (: GetLong :),
              ({"wall"}) : "The grey wall seems to be made out "
                           "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit exists to the east.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"pyramid"}) : "You're inside of it!",
              ({"stone"}) : "A very dark type of stone forms the wall and floor."
           ]) );
  SetItemAdjectives( ([
                       "petroglyphics" : ({"old","scrambled","up","carved"}),
                       "area" : ({"dark"}),
                       "wall" : ({"west","stone","grey"}),
                       "chasm" : ({"dark","black","pitch","bottomless"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"})
                    ]) );

  SetExits( ([ 
              "north" : P_ROOM + "/inter_w2",
              "south" : P_ROOM + "/entrance",
          ]) );
  SetSmell( ([ "default" : "The smell from the chasm is horrible.",
               "chasm" : "The smell coming out is of burnt "
                        "and rotten flesh." ]) );
  SetListen( ([ "default" : "Faint whimpers come out from "
                            "the chasm.",
                "chasm" : "Whimpering and crying can be heard." ]) );
}
/*                                                                   */