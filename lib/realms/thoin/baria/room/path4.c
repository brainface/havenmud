//
// Summary: outside trading hut
//    kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// For Baria
// Date: 26/10/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a small hut");
  SetDayLong("The path ends here at a small hut to the west that looks "
             "very important to the village because of all the people "
             "going in and out of it. To the north only the dense "
             "jungle is visible, while to the south a few huts can be "
             "seen. The path goes back to the east."
            );
  SetNightLong("The darkness of the night makes this place a very "
               "misterious one due to the shadows of the plants and "
               "trees surrounding the area. There is only a small hut "
               "in here from which two lit torches hang, as in every "
               "visible hut to the south. To the north, the obscure "
               "jungle looks like a stalking panther watching every "
               "move. "
               "The nearly invisible path "
               "goes back to the east."
             );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"hut"}) : "This hut is quite small but seems to "
                          "attract quite a crowd.",
              ({"people"}) : "People are coming in and out from the "
                             "hut with several goods in hand.",
              ({"jungle"}) : "The jungle is dense and misterious.",
              ({"huts"}) : "Several huts that conform the village can "
                           "be seen from this point.",
              ({"path"}) : "This path intersects with the main road.",
              ({"shadows","shadow"}) : "These are the shadows of "
                                       "plants and trees that form "
                                       "strange shapes on the ground.",
              ({"torches","torch"}) : "Two lit torches add light to "
                                      "the area.",
              ({"jungle"}) : "The Barian Jungle is seen to the far "
                             "north.",
              ({"plants","plant","trees","tree"}) : "Several plants "
                                                    "and trees "
                                                    "surround the "
                                                    "path and the hut."
          ]) );
  SetItemAdjectives( ([
                       "hut" : ({"small"}),
                       "jungle" : ({"dense","misterious","obscure",
                                    "barian"}),
                       "huts" : ({"several","few"}),
                       "torches" : ({"lit","two"})
                   ]) );
  SetObviousExits("east");
  SetExits( ([
              "east" : BARIA_ROOM + "path2",
          ]) );
  SetEnters( ([
               "hut" : BARIA_ROOM + "tradinghut",
           ]) );
  SetListen( ([ "default" : "One can hear muffled talking from "
                            "inside the small hut." ]) );
  SetSmell( ([ "default" : "There's a strong scent of leather "
                           "combined with burning charcoal." ]) );
}
