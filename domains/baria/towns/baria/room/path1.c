/*                                                                   */
/*    a dusty path in the Barian village
      Kyla 11-1-97
      Modified by Rhakz on 10/12/98
*/
#include <lib.h>
#include <domains.h>
#include "../jungle.h"
inherit LIB_ROOM;

int CheckPC();

static void create() {
  room::create();
  SetShort("an well worn path");
  SetDayLong("This well worn path goes north back into the jungle, "
             "and south into what appears to be some sort of village. "
             "There are exotic plants and flowers on both sides of "
             "the path as if they were watching over it. Two "
             "towering tropical trees mark the entrance to this "
             "village, on which several huts can be seen."
            );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetNightLong("This worn path goes north back into the darkness of "
               "the jungle, and south into some sort of village. "
               "The shadows of the plants and flowers as well as "
               "those from the towering trees form scary shapes "
               "thanks to the dim light coming south from here, "
               "where torches hang from the small huts in the "
               "village."
              );
  SetItems( ([
              ({"path"}) : "This well worn path continues to the "
                           "north and to the south.",
              ({"plant", "plants",
               "flowers","flower"}) : "The plants and flowers are "
                                      "rare but beautiful.",
              ({"hut", "huts" }) : "These huts look as though they "
                                   "have been well constructed and "
                                   "are used quite frequently.",
              ({"trees","tree"}) : "These trees have grown high up "
                                   "towards the sky.",
              ({"shadows","shadow",
                          "shapes"}) : "The shadows take weird forms "
                                       "due to the light.",
              ({"torch","torches"}) : "These torches give out a dim "
                                      "light so the villagers can "
                                      "somewhat see during night.",
              ({"jungle"}) : "The vast jungle lies north of here.",
              ({"village"}) : "There's a small village south of here."  
              
            ]) );
  SetItemAdjectives( ([
                       "path" : ({"well worn","worn"}),
                       "plant" : ({"exotic","rare","beautiful"}),
                       "hut" : ({"small","several"}),
                       "trees" : ({"towering","tropical"}),
                       "shadows" : ({"scary","weird"}),
                       "village" : ({"small"})
                   ]) );
  SetInventory( ([
                  BARIA_NPC + "guard" : 2,
              ]) );
  SetExits( ([
              "south" : BARIA_ROOM + "path2",
           ]) );
  AddExit("north", BARIA_VIRTUAL "jungle/-10,-10", (: CheckPC :) );
  SetSmell( (["default" : "There is a faint scent of cooking food coming "
                          "from the south." ]) );
  SetListen( (["default" : "To the south muffled footsteps and talking "
                           "can be heard." ]) );

}

int CheckPC() {
  if (this_player()->id("baria_wander")) return 0;
    else return 1;
}

