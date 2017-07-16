//
// Summary: outside the common hut
//        Kyla 11-1-97
// Modified by Rhakz - Angel Cazares
// Date: 10/21/98
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a small hut");
  SetDayLong("The intersecting path ends here, at the doorway of a "
             "nice-looking hut. There are waves of smoke coming out "
             "of a chimney located at the top of the hut. A small sign "
             "has been put at the top of the hut's door. "
             "Some barrels can be seen near the walls of this inn."
            );
  SetNightLong("Only the torches hanging from this hut make it "
               "possible to see during the night. There are waves of "
               "smoke coming out of a chimney located at the top of "
               "the hut. A small sign "
               "has been put at the top of the hut's door. "
               "Some barrels can be seen near the walls of this inn."
              );
  SetTown("Baria");
  SetClimate("tropical");
  SetDomain("Baria");
  SetItems( ([
              ({"path"}) : "This well worn path stops here and leads "
                           "to a small hut.",
              ({"hut"}) : "This small hut radiates a friendly aura.",
              ({"doorway"}) : "This is the doorway to the inn.",
              ({"smoke"}) : "The smoke coming out from the chimney is "
                            "dark grey.",
              ({"chimney"}) : "A chimney at the top of the hut from "
                              "where waves of smoke comes out.",
              ({"sign"}) : "Baria's Lodge.",
              ({"barrels","barrel"}) : "These contain some sort of "
                                       "refreshing drink.",
              ({"torches","torch"}) : "This torches make possible to "
                                      "see in this area during night."
          ]) );
  SetItemAdjectives( ([
                       "path" : ({"well worn"}),
                       "hut" : ({"small","friendly","nice-looking"}),
                       "smoke" : ({"dark","grey"}),
                       "sign" : ({"small"})
                   ]) );
  SetExits( ([
              "west" : BARIA_ROOM + "path2",
          ]) );
  SetEnters( ([
               "hut" : BARIA_ROOM + "commonhut",
           ]) );
  SetSmell( ([ "default" : "The scent of food radiates from this "
                           "hut." ]) );
  SetListen( ([ "default" : "The sounds of laughing and singing are "
                            "coming from the hut." ]) );
}

