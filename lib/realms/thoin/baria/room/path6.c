//
// Summary; another intersection
//        Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/29/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("an intersection");
  SetDayLong("This is the second intersection of the main road with a "
             "small east-west path that leads to some huts. More of "
             "these can be seen to the north and farther in that "
             "direction, the dense Barian Jungle lies. South of here "
             "sits the center of the town."
            );
  SetNightLong("This part of Baria would be dark as the night if it "
               "wasn't because of the torches outside the huts "
               "sitting to the east and west. There are other huts "
               "to the south, where the center of the town is, and "
               "to the north. Farther to the north, the dark jungle "
               "awaits."
              );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"intersection"}) : "This is where a small path "
                                   "intersects with the main "
                                   "road.",
              ({"road"}) : "Baria's main road.",
              ({"path"}) : "A small paths travels to the east and "
                           "west.",
              ({"huts","hut"}) : "Several huts can be seen in all "
                                 "directions.",
              ({"jungle"}) : "The misterious Barian Jungle lies "
                             "north.",
              ({"torches","torch"}) : "There are some torches on the "
                                      "huts.",
              ({"town"}) : "The town of Baria."
          ]) );
  SetItemAdjectives( ([
                       "road" : ({"main","baria's"}),
                       "path" : ({"small"}),
                       "huts" : ({"several","some"}),
                       "jungle" : ({"misterious","dense","dark",
                                    "barian"}),
                   ]) );
  SetExits( ([
              "north" : BARIA_ROOM + "path5",
              "south" : BARIA_ROOM +  "path9",
              "east" : BARIA_ROOM + "path7",
              "west" : BARIA_ROOM + "path8",
          ]) );
  SetListen( ([ "default" : "The sounds of the natives working is all "
                            "that can be heard." ]) );
  SetSmell( ([ "default" : "The exquisite scent of flowers fills this "
                           "part of the road." ]) );
}

