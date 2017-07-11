/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: e1.c
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
  SetLong("The big chasm to the west looks frightening "
          "from this side. The petroglyphics in the wall "
          "have increased in number, as if they were announcing "
          "something very important. There's a tile in the "
          "ground that looks different from the others. The "
          "way follows north and south."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "Very important "
                                                   "people are "
                                                   "depicted in the "
                                                   "hieroglyphics. "
                                                   "Perhaps they are "
                                                   "gods.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the west.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"tile"}) : "This odd tile is darker than the others "
                           "and has some cracks on it."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","big",
                                   "obscure","unfriendly"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "tile" : ({"odd","different"})
                    ]) );
  SetExits( ([ 
              "south" : P_ROOM + "/se",
              "north" : P_ROOM + "/inter_e2",
          ]) );
  SetInventory( ([ P_NPC + "/shaman" : 1 ]) );
  SetSmell( ([ "default" : "This area smells of burnt hair."]) ); 
  SetListen( ([ "default" : "People blaspheming and swearing "
                            "can be faintly heard." ]) ); 
}
/*                                                                   */