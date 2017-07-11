//
// Summary: intersection 1
//      Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/22/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an intersection");
  SetDayLong("This is where the village's main road intersects with a "
             "path that leads to some huts east and west of here. The "
             "sun and the rain has made several flowers by each side "
             "of the road to grow and bloom. The main road goes north "
             "to the entrance of the village and south into the center "
             "of it." 
  );
  SetNightLong("Here the main road intersects with a path leading "
               "east and west. This area is very dark and only "
               "a few huts can be seen thanks to the torches hanging "
               "from them. The road continues north and south into "
               "darkness."
  );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"road"}) : "This is Baria's main road. It goes from "
                           "north to south.",
              ({"path"}) : "An intersecting path leads east and "
                           "west into some huts.",
              ({"flowers","flower"}) : "Beautiful flowers are "
                                       "scattered " 
                                       "on each side of the road.",
              ({"huts","hut"}) : "There are some huts to the east and "
                                 "west. A few more can be seen to the "
                                 "south.",
              ({"torches","torch"}) : "This torches hang from the huts, "
                                      "irradiating some light.",
              ({"area"}) : (: GetLong :)
          ]) );
  SetItemAdjectives( ([
                       "road" : ({"main"}),
                       "path" : ({"intersecting"}),
                       "flowers" : ({"beautiful"}),
                   ]) );                
  SetExits( ([
              "north" : BARIA_ROOM + "path1",
              "south" : BARIA_ROOM + "path5",
              "east" : BARIA_ROOM + "path3",
              "west" : BARIA_ROOM + "path4",
          ]) );
  SetSmell( ([ "default" : "The smell of food is strong here and "
                           "seems to come from the east." ]) );
  SetListen( ([ "default" : "The humm of people going about their "
                            "daily routines is all that can be heard." ]) );
  SetInventory( ([
     BARIA_NPC + "wander_guard" : 1,
  ]) );
}
