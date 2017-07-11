/*  Portia  Ruins  10-9-98
    Along the walkway.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
         "north" : RUINS_ROOMS + "5,-4",
         "south" : RUINS_ROOMS + "5,-6",
         "east" : RUINS_ROOMS + "6,-5",
           ]) );
  SetInventory( ([
/*
         RUINS_NPC + "lizardman2" : 1,
*/
            ]) );
  SetListen( ([
          "default" : "The jungle birds can be heard from here.",
           ]) );
  SetSmell( ([
         "default" : "The air has a reptilian odor in it.",
           ]) );
  SetLong("The walkway continues north and south from here. "
          "To the north lies more of the village while the jungle " 
          "lies to the south. The path also curves around to the east "
          "where it seems that the village continues. A large building "
          "with no roof is to the west.");
  SetItems( ([
        ({"walkway", "path"}) : (:GetLong:),
         "village" : "The village lies to the north and to the east.",
         "jungle" : "The jungle is south of here.",
         "building" : "The building is still mostly erected, missing "
                      "only the ceiling.",
          ]) );
  SetItemAdjectives( ([
       "walkway" : "dusty",
       "building" : "large",
         ]) );
  SetEnters( ([
       "building" : RUINS_ROOMS + "house3",
          ]) );
  }
/*   [ Portia Approved ] */
