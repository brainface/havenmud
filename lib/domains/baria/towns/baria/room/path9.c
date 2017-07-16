
//
// Summary: center of the town
//      kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/31/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("the center of the village");
  SetLong("This is the center of the village of Baria, where the main "
          "road breaks into three small paths to the south. The "
          "inhabitants of the town like to gather here and spend "
          "their time chatting while drinking from the old fountain. "
          "There are several huts to the south, but the one sitting "
          "straight south is very large and imposing."
         );
  SetTown("Baria");
  SetDomain("Baria");
  SetClimate("tropical");
  SetItems( ([
              ({"road"}) : "This is the main road of the village.",
              ({"paths","path"}) : "There are three small paths to "
                                   "the south, southwest and southeast.",
              ({"huts","hut"}) : "Several huts can be seen south of here, "
                                 "but one of is very large and looks very "
                                 "important."
          ]) );
  SetItemAdjectives( ([
                       "road" : ({"main"}),
                       "paths" : ({"small"}),
                       "huts" : ({"several","large","imposing",
                                  "important"})
                   ]) );
  SetExits( ([
              "southeast" : BARIA_ROOM + "path11",
              "north" : BARIA_ROOM + "path6",
              "south" : BARIA_ROOM + "path12",
              "southwest" : BARIA_ROOM + "path10",
          ]) );
  SetInventory( ([
                  BARIA_NPC + "wander_guard" : 1,
                  BARIA_OBJ + "dragon_statue" : 1,
                  BARIA_OBJ + "pool" : 1,
                  BARIA_NPC + "alkor" : 1,
                  BARIA_NPC + "quest/merchant" : 1,
                  BARIA_NPC + "controller" : 1,
              ]) );
  SetListen( ([ "default" : "The sounds of the village are loud and "
                            "are all that can be heard." ]) );
  SetSmell( ([ "default" : "The perfume of fresh plants is mixed "
                           "with that of fresh flowers." ]) );
}
