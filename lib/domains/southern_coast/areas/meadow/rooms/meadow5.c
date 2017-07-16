/* a meadow room
    Kyla 10-16-97
*/
#include <lib.h>
#include "../meadow.h"
inherit LIB_ROOM;
string MeadowSearch();

static void create() {
  room::create();
  SetShort("a meadow");
  SetObviousExits("west, south");
  SetExits( ([
          "west" : MEADOW_ROOMS + "meadow4",
         "south" : MEADOW_ROOMS + "meadow9",
          ]) );
  SetSmell( ([
          "default" : "The smell of grass is abundant here.",
           ]) );
  SetListen( ([
            "default" : "The sound of waves can be heard far off "
                         "to the south."
            ]) );
  SetLong("To the east and to the south there only appears to be "
           "more meadow. There are some footprints here, that seem "
            "as if they have been here for quite some time. To the "
           "south the grass appears to be shorter and flattened."
           " There appears to be something to the east."
           );
  SetItems( ([
            ({"footprint", "footprints"}) : "These footprints appear "
                                        "to be those of a creature that "
                                         "walks upright.",
            "grass" : "This tall brown grass seems to be shorter " 
                       "off to the south.",
           ]) );
  SetSearch( ([
             "default" : (: MeadowSearch :),
             ]) );
  }

string MeadowSearch() {
  if (GetExit("east")) {
    return "The area has already been searched to reveal an exit to the east.";
    }
  AddExit("east", MEADOW_ROOMS + "meadow5a");
  return "You find an exit to the east!";
  }
