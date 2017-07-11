/*   Portia  Ruins  10-10-98
     A walkway through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway.");
  SetClimate("tropical");
  SetExits( ([
      "south" : RUINS_ROOMS + "7,-4",
      "west" : RUINS_ROOMS + "6,-3",
        ]) );
  SetListen( ([
      "default" : "Birds can be heard to the north.",
          ]) );
  SetSmell( ([
       "default" : "The area smells very earthen.",
        ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman1" : 1,
*/
         ]) );
  SetLong("The path leads west and south here, both directions continuing "
         "through the village. A large wall stands to the north and it "
         "is apparently all that was left of a home after the attack. "
        "To the east lies another building, this one is mostly intact, "  
        "missing only the ceiling.");
  SetItems( ([
        "walkway" : (:GetLong:),
       ({"wall", "home"}) : "This is a single stone wall.",
        ({"west building", "building" }) : "This building looks very stable.",
         ]) );
  SetItemAdjectives( ([
         "walkway" : "dusty",
         "wall" : ({"stone", "large"}),
         "west building" : "stable",
            ]) );
  SetEnters( ([
      "west building" : RUINS_ROOMS + "shop3",
         ]) );
  }
