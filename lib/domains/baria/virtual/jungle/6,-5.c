/*  Portia  Ruins  10-10-98
      A walkway through the village.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a dusty walkway");
  SetClimate("tropical");
  SetExits( ([
        "north" : RUINS_ROOMS + "6,-4",
        "south" : RUINS_ROOMS + "6,-6",
        "west" : RUINS_ROOMS + "5,-5",
          ]) );
  SetInventory( ([
/*
        RUINS_NPC + "python" : 1,
*/
       ]) );
  SetSmell( ([
       "default" : "The air smells faintly of smoke.",
        ]) );
  SetListen( ([
        "default" : "Birds can be heard in the distance.",
          ]) );
  SetLong("The walkway curves here, leading farther into the village "
          "to the north and the west. The jungle can be seen to the south "
          "and a large building lies to the east. Thick foliage blocks the "
          "entrance to this building and one can not get in.");
  SetItems( ([
         ({"walkway", "village" }) : (:GetLong:),
       "jungle" : "The jungle can be seen to the south.",
       ({"building", "entrance"}) : "The entrance to the building is "
                             "blocked by vines.",
        ({"thick foliage", "foliage", "vines", "thick vines", "vine"}) : 
                     "The foliage blocks the entrance to the building.",
       ]) );
  SetItemAdjectives( ([
        "walkway" : "dusty",
         "building" : "large",
          ]) );
  }
