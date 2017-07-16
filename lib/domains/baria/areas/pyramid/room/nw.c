/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: nw.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("the northwest corner of the pyramid");
  SetLong("A tiny torch lights this area dimly, allowing a better "
          "view to the petroglyphics carved in the walls. To the "
          "southeast, the ground disappears into a deep and dark "
          "chasm. Also, the walls in here seem to be decorated with "
          "some jewels. A large green statue stands imposingly by "
          "the northern wall. The way extends to the east, and south into "
          "darkness. "
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic"}) : "They are depicting "
                                                   "the important people "
                                                   "in a place high above "
                                                   "from the normal ones, "
                                                   "watching over them.",
              ({"area"}) : (: GetLong :),
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone, and "
                                   "they're decorated with beautiful gems.",
              ({"chasm","pit"}) : "A dark bottomless pit exists to the southeast.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"torch"}) : "A small torch gives out some light.",
              ({"jewels","jewel","gems"}) : "Several pieces of beautiful "
                                            "gems decorate the walls.",
              ({"stone"}) : "A very dark type of stone forms the walls "
                            "and floor.",
              ({"statue"}) : "This giant bat-like statue stands still "
                             "in the room. It's made of green jade."
           ]) );
  SetItemAdjectives( ([
                       "petroglyphics" : ({"old","carved"}),
                       "area" : ({"light"}),
                       "walls" : ({"stone","decorated","north","northern"}),
                       "chasm" : ({"dark","deep","bottomless","and"}),
                       "floor" : ({"tiled"}),
                       "torch" : ({"tiny"}),
                       "jewels" : ({"beautiful"}),
                       "stone" : ({"dark","grey","decorated","tiled"}),
                       "statue" : ({"large","imposing","bat-like",
                                    "giant","green","jade"})
                    ]) );
  SetExits( ([ 
              "east" : P_ROOM + "/n1",
              "south" : P_ROOM + "/w3",
          ]) );
  SetInventory( ([ P_NPC + "/lizardman_nw" : 1 ]) );
  SetSmell( ([ "default" : "A disgusting smell comes from the "
                           "southeast." ]) ); 
  SetListen( ([ "default" : "Strangely, no sounds are heard." ]) ); 
}
/*                                                                   */
