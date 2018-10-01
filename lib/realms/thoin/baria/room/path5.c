/*   a small path 
       Kyla 11-1-97
*/
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the main road");
  SetDayLong("Exotic trees and plants surround this part of the main "
             "road of the village of Baria, going north "
             "to the dangerous jungle and south to the center of the "
             "village. Some huts can be seen to the north and to the "
             "south, this last ones looking more important than the "
             "others."
            );
  SetNightLong("This is the main road of Baria, which travels north "
               "into the dark and shadowy jungle and south towards "
               "the center of the village. The only light that can "
               "be seen is that of the torches hanging from the "
               "several huts standing north and south of here."
              );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"trees","tree","plants","plant","trees and plants",
                "plants and trees"}) : "Several tropical plants "
                                       "and trees surround "
                                       "Baria's main road.",
              ({"road"}) : "Baria's main road goes north and south.",
              ({"jungle"}) : "The misterious Barian Jungle stands to "
                             "the north.",
              ({"village"}) : "The village of Baria sits deep inside "
                              "the Brian Jungle.",
              ({"huts","hut"}) : "Several huts are scattered among "
                                 "the village.",
              ({"light","torches","torch"}) : "Two torches hang from "
                                              "the outside of each "
                                              "hut."
          ]) );
  SetItemAdjectives( ([
                       "trees" : ({"exotic","tropical"}),
                       "road" : ({"main","baria's main"}),
                       "jungle" : ({"misterious","dark","shadowy",
                                    "and"}),
                       "huts" : ({"several"})
                   ]) );
  SetExits( ([
              "north" : BARIA_ROOM + "path2",
              "south" : BARIA_ROOM + "path6",
          ]) );
  SetListen( ([ "default" : "More sounds of life are coming from the "
                            "south." ]) );
  SetSmell( ([ "default" : "The faint scent of tropical flowers "
                           "floats in the air." ]) );
}

