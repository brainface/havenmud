/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: inter_e2.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(10);
  SetShort("the eastern intersection with a bridge");
  SetLong("A bridge coming from the east intersects with the road "
          "in this area. The petroglyphics on the wall to the east "
          "begin to take more interesting forms as the series go on "
          "and on. The stones forming the floor tile up to contine "
          "their way north and south, and to the west lies the bridge."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "The petroglyphics " 
                                                   "start to describe "
                                                   "some sort of birth.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the southwest and to the northwest,"
                                  "passing below the bridge.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"area"}) : (: GetLong :),
              ({"bridge"}) : "A stone-made bridge lies to the west.",
              ({"series"}) : "Series of petroglyphics are carved on "
                             "the wall."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","big",
                                   "obscure","unfriendly"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "petroglyphics" : ({"wall-carved",
                                           "series of"}),
                       "bridge" : ({"stone-made"})
                    ]) );
  SetExits( ([ 
              "south" : P_ROOM + "/e1",
              "north" : P_ROOM + "/e3",
              "west" : P_ROOM + "/bridge_ew1"
          ]) );
  SetSmell( ([ "default" : "It smells of decay."]) ); 
  SetListen( ([ "default" : "Endless crying comes from "
                            "far away." ]) ); 
}
/*                                                                   */