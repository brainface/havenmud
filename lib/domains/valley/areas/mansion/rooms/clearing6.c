/* a small clearing
    kyla 2-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a small clearing");
SetDomain("Valley");
  SetClimate("temperate");
  SetExits( ([
      "east" : MANSION_ROOMS + "clearing7",
      "west" : MANSION_ROOMS + "clearing5",
      "south" : MANSION_ROOMS + "bridge",
      "southeast" : MANSION_ROOMS + "moat5",
      "southwest" : MANSION_ROOMS + "moat4",
          ]) );
  SetInventory( ([
       CLEARING_NPC + "huntdog" : 2,
               ]) );
  SetListen( ([
       "default" : "The area is unusually quiet",
            ]) );
  SetSmell( ([
       "default" : "There is a very foul odor coming from the south.",
           ]) );
  SetLong("The entire area is covered in grass except for the small "
          "dusty path. The clearing extends to the east and west and "
          "there seems to be some sort of bridge to the south. A few "
          "bushes scatter the area and there is an occasional sapling.");
  SetItems( ([
    ({"area", "clearing"}) : (:GetLong:),
         "grass" : "The grass has been bleached by the hot sun.",
         "path" : "The small path takes a turns through the southwest "
                   "corner of this section of the clearing.",
        "bridge" : "What appears to be a bridge lies to the south.",
    ({"bush", "bushes"}) : "These small bushes are scattered throught the "
                             "clearing.",
    ({"sapling", "saplings"}) : "These small trees are few here.",
            ]) );
  }
