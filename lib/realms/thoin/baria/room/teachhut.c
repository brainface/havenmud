//
// Summary: language teachers hut
//        Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/20/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a medium sized hut");
  SetObviousExits("out");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetExits( ([
        "out" : BARIA_ROOM + "path11",
         ]) );
  SetTown("Baria");
  SetInventory( ([
         BARIA_NPC + "ariana" :1,
              ]) );
  SetLong("There are several shelves accommodated by the walls of this "
          "hut. The shelves contain books dealing with different "
          "subjects. There's a primitive blackboard hanging from "
          "one of the walls which is used by Ariana when someone "
          "request her services as a teacher. There is a large rug "
          "covering the floor for students to sit down."
         );
  SetItems( ([
              ({"rug"}) : "This elegant rug is a warm covering for "
                          "the cold dirt ground.",
              ({"floor"}) : "A dirty floor.",
              ({"wall", "walls"}) : "The walls are made of wood and "
                                    "leaves.",
              ({"blackboard"}) : "This wooden blackboard is in bad "
                                 "shape.",
              ({"shelves","shelf"}) : "This wooden shelves support "
                                      "many books.",
              ({"books","book"}) : "Different themes are covered by "
                                   "the books in the shelves."
            ]) );
  SetItemAdjectives( ([
                       "rug" : ({"elegant","large"}),
                       "floor" : ({"dirty"}),
                       "wall" : ({"wooden"}),
                       "blackboard" : ({"primitive"}),
                       "shelves" : ({"wooden","several"})
                   ]) );
  SetSmell( ([ "default" : "Particles of dust and chalk float in "
                           "the air." ]) );
  SetListen( ([ "default" : "Children can be heard playing "
                            "outside." ]) );
}

