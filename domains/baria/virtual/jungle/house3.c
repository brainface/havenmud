/*  Portia   10-9-98  Ruins
    A house to be entered from "5,-5".
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small dwelling");
  SetClimate("tropical");
  SetExits( ([
        "out" : RUINS_ROOMS + "5,-5",
       ]) );
  SetSmell( ([
     "default" : "The room smells very reptilian.",
         ]) );
  SetListen( ([
      "default" : "The sound of footsteps can be heard outside.",
         ]) );
  SetInventory( ([
/*
        RUINS_NPC + "lizardman3" : 1,
*/
       ]) );
  SetLong("This home is mostly still standing. The only problem is the "
         "lack of a ceiling. All of the residents' possesions have either "
        "been stolen or destroyed. All that remains in the room is "
        "a single chair.");
  SetItems( ([
     ({"dwelling", "home"}) : (:GetLong:),
      ({"single chair", "chair"}) : "The chair is very basic and looks "
                       "very old.",
        ]) );
  SetItemAdjectives( ([
        "chair" : ({"basic", "old"}),
          ]) );
  }
/*   [ Portia Approved ] */
