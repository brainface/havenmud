/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: e3.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("along the eastern side of the pyramid");
  SetLong("This area has no illumination, making it as dark as "
          "the night. The wall has a series of petroglyphics "
          "carved on it, as well as a lot of dust. There's a "
          "big and obscure chasm that looks very unfriendly. "
          "The way continues north, where the area is more "
          "illuminated, and south."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic","signs",
                "sign"}) : "The scrambled up signs are "
                           "beginning to take form.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the west.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"area"}) : (: GetLong :)
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","big",
                                   "obscure","unfriendly"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "petroglyphics" : ({"scrambled","wall-carved",
                                           "series of"})
                    ]) );
  SetExits( ([ 
              "south" : P_ROOM + "/inter_e2",
              "north" : P_ROOM + "/ne",
          ]) );
  SetSmell( ([ "default" : "The smell of decay is getting "
                           "stronger."]) ); 
  SetListen( ([ "default" : "The voices are increasing in tone." ]) ); 
}
/*                                                                   */