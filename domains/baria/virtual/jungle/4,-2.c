/* Portia 10-6-98  Ruins
    Jungle border room
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sweltering jungle");
  SetExits( ([
          "north" : "/domains/baria/virtual/jungle/4,-1",
          "west" : "/domains/baria/virtual/jungle/3,-2",
          "east" : RUINS_ROOMS + "5,-2",
          "south" : RUINS_ROOMS + "4,-3",
          ]) );
  SetClimate("tropical");
  SetListen( ([
       "default" : "Many different types of jungle birds can be heard.",
        ]) );
  SetSmell( ([
      "default" : "The only odor is that of the dense moss.",
         ]) );
  SetInventory( ([
/*
      RUINS_NPC + "ape" : 1,
*/
       ]) );
  SetLong("The jungle seems to be thinning out here. There seems to be "
          "some sort of building to the southwest though it is hard to "
          "determine through the trees. There is a small pathway that "
          "leads east, but it is mostly covered in vines and moss and "
          "doesn't appear to be used very often.");
  SetItems( ([
      "jungle" : (:GetLong:),
      "moss" : "This moss is very thick and covers everything in sight.",
      "building" : "The building is barely visible through the foliage.",
      ({"trees", "foliage", "tree"}) : "The trees and other foliage "
                       "don't allow one to see very far.",
      ({"small pathway", "pathway", "path", "small path"}) : "The path is "
                       "covered in vines and looks very old.",
       ({ "vines", "vine" }) : "The vines hang down from the trees and "
                       "make moving a bit more difficult.",
       ]) );
  SetItemAdjectives( ([
       ]) );
  }
/*   [ Portia approved ] */
