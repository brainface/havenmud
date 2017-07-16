/*  Portia  10-10-98  Ruins
     a path through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "7,-3",
        "south" : RUINS_ROOMS + "7,-5",
           ]) );
/*
  SetInventory( ([
        RUINS_NPC + "lizardman3.c" : 1,
         ]) );
*/
  SetSmell( ([
       "default" : "The area smells very reptilian.",
          ]) );
  SetListen( ([
       "default" : "The area is very quite.",
           ]) );
  SetLong("The walkway continues to the north and south from here. "
          "To the west there is the back of a large building, and "
          "another building lies to the east. There is much foliage "
         "here, and it seems as though there has been no attempt "
        "to clean up after whatever attack destroyed this village.");
  SetItems( ([
       "walkway" : (:GetLong:),
       ({"west building", "wall", "back wall"}) : "This is the back wall of "
                               "a large building.",
       ({"east building", "building"}) : "The large building is covered "
                                "in foliage.",
          "foliage" : "The foliage is very thick here.",
           ]) );
  SetItemAdjectives( ([
        "walkway" : "dusty",
           ]) );
  SetEnters( ([
         "east building" : RUINS_ROOMS + "shop1",
             ]) );
  }
