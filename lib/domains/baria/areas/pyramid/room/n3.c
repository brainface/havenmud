/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: n3.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(25);
  SetShort("along the northern side of the pyramid");
  SetLong("A glowing jade statue stands here as if it was watching "
          "over the place. To the south, an ominous chasm has "
          "eaten the tiled floor. Two small torches dimly "
          "illuminate the area, but the chasm seems to swallow "
          "part of the light. The path goes west and east."
	    );
  SetItems( ([
              ({"area","place"}) : (: GetLong :),
              ({"walls","wall"}) : "The walls seem to be made out "
                                   "of perfectly cut dark stone.",
              ({"chasm","pit"}) : "A dark bottomless pit can be seen "
                                  "to the south. It swallows part of "
                                  "this area's light.",
              ({"ground","floor"}) : "The floor is made up of "
                                     "stones tiled together.",
              ({"torch","torches"}) : "A couple of small torches "
                                      "illuminate the area.",
              ({"stone","stones"}) : "A very dark type of stone "
                                     "forms the walls "
                                     "and floor.",
              ({"statue"}) : "A dog-like statue made of jade stands "
                             "here, glowing with the flickering light "
                             "of the torches."
           ]) );
  SetItemAdjectives( ([
                       "walls" : ({"stone","dark"}),
                       "chasm" : ({"dark","bottomless","ominous"}),
                       "floor" : ({"tiled"}),
                       "torch" : ({"small"}),
                       "stone" : ({"dark","grey","tiled"}),
                       "statue" :({"jade","glowing","dog-like"}),
                    ]) );
  SetExits( ([ 
              "east" : P_ROOM + "/ne",
              "west" : P_ROOM + "/inter_n2",
          ]) );
  SetSmell( ([ "default" : "The smell of rottenness fills this place."]) ); 
  SetListen( ([ "default" : "Noises of something crawling "
                            "is all around the area." ]) ); 
}
/*                                                                   */