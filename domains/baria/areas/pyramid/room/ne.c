/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: ne.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("the northeastern corner of the pyramid");
  SetLong("A series of wall-carved petroglyphics start here on "
          "the wall to the east. To the north, a large statue "
          "keeps eternally watching the pyramid. The flames of two "
          "lit torches flicker as if there was a current of air. "
          "Southwest of here, a deep chasm forms taking the place "
          "of the ground. "
          "The tiled floor goes west, and south into darkness."
	    );
  SetItems( ([
              ({"petroglyphics","petroglyphic",
                "signs","sign"}) : "Some sort of "
                                   "scrambled up "
                                   "signs carved "
                                   "on the wall.",
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the southwest.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"torch","torches"}) : "A couple of small torches "
                                      "illuminate the area.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"statue"}) : "A big snake-like statue stands "
                             "here. It is made of green jade.",
              ({"flame"}) : "The flame from the torches flickers constantly."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","ominous"}),
                       "floor" : ({"tiled"}),
                       "torch" : ({"small"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "statue" :({"big","large","snake-like","jade"}),
                       "flame" : ({"flickering"}),
                       "petroglyphics" : ({"scrambled","wall-carved",
                                           "series of"})
                    ]) );
  SetExits( ([ 
              "south" : P_ROOM + "/e3",
              "west" : P_ROOM + "/n3",
          ]) );
  SetInventory( ([ P_NPC + "/lizardman_ne" : 1 ]) );
  SetSmell( ([ "default" : "The smell of decay "
                           "is strong."]) ); 
  SetListen( ([ "default" : "The faint voice of someone begging for "
                            "help can be heard." ]) ); 
}
/*                                                                   */
