//
// Summary: path by language and hunter huts
//         Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 11/01/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small path");
  SetLong("This small path stops here, where two important huts have "
          "been built, one to the south and other to the east. The hut "
          "to the south is decorated with paintings and has two crossed "
          "spears above the entrance, while the one to the east looks "
          "quite simple. Several trees surround the huts in a hiding "
          "manner. The path returns to the west and northwest."
         );
  SetTown("Baria");
  SetDomain("Baria");
  SetClimate("tropical");
  SetItems( ([
              ({"path"}) : "This small path stops here, but continues "
                           "back to the west and northwest.",
              ({"south hut", "hut"}) : "This hut appears to be quite "
                                       "large and must belong to "
                                       "someone of importance.",
              ({"paintings","painting"}) : "Animals and hunting "
                                           "scenes are painted on "
                                           "the south hut.",
              ({"spears","spear"}) : "These spears suggest that the "
                                     "owner of the south hut embraces "
                                     "hunting-like activities.",
              ({"trees","tree"}) : "Giant tropical trees surround the "
                                   "huts.",
              ({"east hut", "hut"}) : "This hut is not quite as big "
                                      "as the one to the south, yet "
                                      "still seems important.",
          ]) );
  SetItemAdjectives( ([
                       "path" : ({"small"}),
                       "south hut" : ({"large","decorated"}),
                       "spears" : ({"crossed"}),
                       "trees" : ({"giant","tropical","several"}),
                       "east hut" : ({"important"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "kids"  : 2
              ]) );
  SetObviousExits("west, northwest");
  SetExits( ([
              "west" : BARIA_ROOM + "path12",
              "northwest" : BARIA_ROOM + "path9",
          ]) );
  SetEnters( ([
               "south hut" : BARIA_ROOM + "hunter_hut",
               "east hut" : BARIA_ROOM + "teachhut",
           ]) );
  SetSmell( ([ "default" : "The scents of dust and decay permeate "
                           "the area." ]) );
  SetListen( ([ "default" : "Faint voices in many languages can be "
                            "heard." ]) );
}

