/* Portia 10-6-98  Ruins
   Jungle border room
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a sweltering jungle");
  SetClimate("tropical");
  SetListen( ([
     "default" : "There seem to be some noises coming from the east.",
       ]) );
  SetSmell( ([
     "default" : "The faint scent of smoke is in the air.",
         ]) );
  SetInventory( ([
/*
       RUINS_NPC + "lizardman3" : 1,
*/
        ]) );
  SetExits( ([
      "north" : RUINS_ROOMS + "4,-2",
      "west" : "/domains/baria/virtual/jungle/3,-3",
      "south" : RUINS_ROOMS + "4,-4",
      ]) );
  SetLong("The jungle is quite thin here, and there is a large stone "
          "wall blocking the way to the east. The area seems as though "
          "no one has been here in quite some time, but the wall indicates "
         "without a doubt that someone lived here once. The jungle becomes "
        "more dense to the west.");
  SetItems( ([
      "jungle" : (:GetLong:),
      ({"large wall", "wall"}) : "This large stone wall looks almost "
                   "ancient and effectively blocks your way to the east.",
      "area" : (:GetLong:),
       ]) );
  SetItemAdjectives( ([
      "jungle" : ({"sweltering", "thin"}),
      "wall" : ({"stone", "large"}),
      ]) );
  }
/*   [ Portia approved ] */
