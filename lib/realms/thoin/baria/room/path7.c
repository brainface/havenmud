//
// Summary: outside a small dwelling
//      Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/30/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in front of a small hut");
  SetLong("The east part of this small path leads to the entrance of "
          "a small but comfortable-looking hut. It is surrounded by "
          "beautiful white flowers that seem to dance with the wind. "
          "Several small footprints of a human are near the entrance, "
          "perhaps a small child lives inside the hut. The path "
          "returns west to the main road."
         );
  SetTown("Baria");
  SetDomain("Baria");
  SetClimate("tropical");
  SetItems( ([
              ({"path"}) : "This small offshoot from the main path "
                           "ends at the entrance to this hut.",
              ({"flowers","flower"}) : "Several white flowers decorate "
                                       "the entrance and the "
                                       "surroundings of the hut.",
              ({"hut"}) : "A small hut where barians can live.",
              ({"footprint","footprints"}) : "These small footprints "
                                             "appear to "
                                             "belong to a small human.",
              ({"road"}) : "Baria's main road is to the west.",
          ]) );
  SetItemAdjectives( ([
                       "path" : ({"small"}),
                       "flowers" : ({"white","beautiful"}),
                       "hut" : ({"small","comfortable-looking"}),
                       "footprints" : ({"small"}),
                       "road" : ({"main","baria's"})
                   ]) );
  SetObviousExits("west");
  SetExits( ([
              "west" : BARIA_ROOM + "path6",
          ]) );
  SetEnters( ([
               "hut" : BARIA_ROOM + "dwelling1",
           ]) );
  SetListen( ([ "default" : "From here one can hear the cry of a "
                            "small child." ]) );
  SetSmell( ([ "default" : "The white flowers perfume the air." ]) );
}

