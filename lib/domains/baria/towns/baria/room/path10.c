//
// Summary: outside bank's and mayor's huts
// Created by: Kyla
// Modified by Rhakz - Angel Cazares
// Date: 10/31/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside some huts");
  SetLong("At the end of the path lies a large hut which looks very "
          "important to the town due to the activity it shows. Another "
          "hut lies to the south, which looks very regal. The path "
          "follows east to another branch of the town's main road, "
          "and northeast to the town's center where an old fountain "
          "can be seen."
         );
  SetTown("Baria");
  SetDomain("Baria");
  SetClimate("tropical");
  SetItems( ([
              ({"south hut","hut"}) : "This large hut appears to be "
                                      "very important.",
              ({"west hut","hut"}) : "This hut is bustling with "
                                     "activity.",
              ({"path","road"}) : "This is a branch of the main road "
                                  "in the village.",
              ({"fountain","old fountain"}) : "An old fountain sits "
                                              "northeast of here."
          ]) );
  SetObviousExits("east, northeast");
  SetInventory( ([
              ]) );
  SetEnters( ([
               "south hut" : BARIA_ROOM + "mayor_hut",
               "west hut" : BARIA_ROOM + "bank"
           ]) );
  SetExits( ([
              "east" : BARIA_ROOM + "path12",
              "northeast" : BARIA_ROOM + "path9",
           ]) );
  SetSmell( (["default" : "There is a slight scent of incense "
                          "here." ]) );
  SetListen( ([ "default" : "Wind chimes are faintly heard." ]) );
}

