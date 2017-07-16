/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: center.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"
inherit LIB_ROOM;

int PreEnter(string dir);

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("the center of the pyramid");
  SetLong("This is the center of the pyramid. The area here seems to "
          "have an illumination of its own. Powerful, but yet unknown "
          "energies can be felt in the very center of this place, marked "
          "by an odd glowing tile in the floor, from which a "
          "%^BLUE%^blue pillar "
          "of light%^RESET%^ emerges and goes deep into the "
          "darkness above. The road splits up in four ways, each "
          "one going to a side of the pyramid."
	    );
  SetItems( ([
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the south and to the north.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"bridge"}) : "This bridge looks very old. It goes to "
                             "the east and to the west.",
              ({"stone"}) : "A very dark type of stone forms the wall "
                            "and floor.",
              ({"pyramid"}) : "You're inside of it!",
              ({"tile"}) : "An odd tile with an eye carved on it. A pillar "
                           "of blue light emerges from it.",
              ({"road"}) : "It goes north, south, east and west.",
              ({"pillar"}) : "A blue pillar of light emerges here. "
                             "It goes from the ground to the "
                             "darkness seen above."
           ]) );
  SetItemAdjectives( ([
                       "chasm" : ({"dark","bottomless","and"}),
                       "floor" : ({"tiled"}),
                       "stone" : ({"grey","tiled","dark"}),
                       "tile" : ({"odd"}),
                       "pillar" : ({"blue","light","of light"})
                    ]) );
  SetExits( ([ 
              "west" : P_ROOM + "/bridge_ew2",
              "east" : P_ROOM + "/bridge_ew1",
              "north" : P_ROOM + "/bridge_ns1",
              "south" : P_ROOM + "/bridge_ns2"
          ]) );
  SetSmell( ([ "default" : "There's no unusual smell." ]) );
  SetListen( ([ "default" : "Only silence can be heard." ]) );
  SetInventory( ([ 
                  P_OBJ + "/stela" : 1 
              ]) );
  AddEnter( "pillar", P_ROOM + "/blurry", (: PreEnter :) );
}

int PreEnter(string dir) {
  write("As you try to enter the pillar, you're bumped by two "
        "guardians coming out from it!");
  AddInventory( P_NPC + "/mazatl", 1);
  AddInventory( P_NPC + "/tlaloc", 1);
  return 0;
}
/*                                                                   */
