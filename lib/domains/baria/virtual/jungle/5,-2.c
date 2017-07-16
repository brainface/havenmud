/* Portia Ruins 10-8-98
   A jungle border room.
*/

#include <lib.h>
#include "../ruins.h"
inherit LIB_ROOM;

static void create() {
  room::create();

  SetShort("a sweltering jungle");
  SetClimate("tropical");
  SetExits( ([
        "north" : JUNGLE + "5,-1",
        "south" : RUINS_ROOMS + "5,-3",
        "west" : RUINS_ROOMS + "4,-2",
        "east" : RUINS_ROOMS + "6,-2",
              ]) );
  SetListen( ([
       "default" : "The sounds of birds can be heard in the distance.",
          ]) );
  SetSmell( ([
       "default" : "The scent of smoke is in the air.",
          ]) );
  SetInventory( ([
/*
           RUINS_NPC + "python" : 1,
           RUINS_NPC + "lizardman1" : 1,
*/
           ]) );
  SetLong("The jungle is quite thin here, and it seems as though it "
          "may have been cleared on purpose. A small path leads from the "
          "west and heads south into what looks like a village. The jungle "
         "remains thin to the east and to the west, but gets very dense "
         "to the north. There are a few scattered footprints near the path.");
  SetItems( ([
        "jungle" : (:GetLong:),
      ({"small path", "path"}) : "The path leading south and east is "
                          "mostly covered with moss.",
     ({"footprints", "footprint"}) : "These footprints have clawlike features.",
      ({"features", "feature"}) : "These features indicate the creature has claws.",
        "moss" : "The green moss covers the path almost completly.",
        "village" : "What appears to be a villiage lies to the south "
                    "past the building.",
            ]) );
  SetItemAdjectives( ([
         "moss" : ({"green"}),
            ]) );
  }
/*   [ Portia approved ] */
