/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: inter_n2.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("the northern intersection with a bridge");
  SetLong("Here, the road intersects with a bridge to the south. "
          "In the wall to the north, a small jade statue can be "
          "seen. Two small torches hanging from the wall emit "
          "an eerie blue light. There is a dark chasm to the "
          "southwest that extend to the southeast passing "
          "below the bridge. The tiled floor "
          "makes its way to the east and west, and south into "
          "the bridge."
	    );
  SetItems( ([
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the southwest. It extends "
                                  "to the southeast passing below "
                                  "the bridge.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"torch","torches"}) : "A couple of small torches "
                                      "emit a strange blue light.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"statue"}) : "A small eagle-like statue made out of "
                             "green jade, glows with the "
                             "light from the torches.",
              ({"light"}) : "This eerie blue light is emitted by the "
                            "torch.",
              ({"bridge"}) : "The bridge makes its way to the south."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","obstructed"}),
                       "chasm" : ({"dark","bottomless"}),
                       "floor" : ({"tiled"}),
                       "torch" : ({"small"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "statue" :({"jade","small","eagle-like"}),
                       "light" : ({"blue","eerie","strange"})
                    ]) );
  SetInventory( ([ P_NPC + "/lizardman_center" : 1 ]) );
  SetExits( ([ 
              "east" : P_ROOM + "/n3",
              "west" : P_ROOM + "/n1",
              "south" : P_ROOM + "/bridge_ns1"
          ]) );
  SetSmell( ([ "default" : "The air carries the smell of decomposing "
                           "flesh."]) ); 
  SetListen( ([ "default" : "Mixed sounds of crying and yelling "
                            "can be heard." ]) ); 
}
/*                                                                   */
