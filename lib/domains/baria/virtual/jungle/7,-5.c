/*  Portia  Ruins  10-10-98
    A village walkway.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "7,-4",
        "south" : RUINS_ROOMS + "7,-6",
        ]) );
  SetSmell( ([
        "default" : "The area smells of decaying moss.",
        ]) );
  SetListen( ([
        "default" : "The sounds of birds can be heard.",
         ]) );
  SetInventory( ([
/*
       RUINS_NPC + "toucan" : 1,
*/
           ]) );
  SetLong("This is an entrance to the village. The jungle lies "
          "to the south and there is a path that leads north. "
         "Two piles of stone lie to the east and west. The piles "
         "are huge and block those directions efficiently. It seems as "
         "though no one has been here in many, many years.");
  SetItems( ([
        ({"walkway", "entrance", "village" }) : (:GetLong:),
      "jungle"  : "The jungle is south of here.",
        "path" : "The path is very dusty.",
        ({"piles of stone", "piles", "pile", "stone"}) : "The piles of stone "
                     "are very large.",
         ]) );
  SetItemAdjectives( ([
        "walkway" : "dusy",
        "piles of stone" : "large",
           ]) );
  }
