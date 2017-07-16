/* a clearing
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
  SetInventory( ([
      CLEARING_NPC + "baby_deer" : 2,
      ]) );
  SetExits( ([
      "south" : MANSION_ROOMS + "pasture1",
      "southeast" : MANSION_ROOMS + "pasture2",
      "east" : MANSION_ROOMS + "clearing2",
        ]) );
  SetSmell( ([
    "default" : "The only scent is the smell of long grass.",
          ]) );
  SetListen( ([
    "default" : "Chirping birds can be heard in the distance.",
            ]) );
  SetLong("The grass is matted in this part of the clearing. "
         "To the south lies what appears to be a pasture and "
         "the clearing extends to the east. A few bushes scatter "
        "the area along with a few young saplings.");
  SetItems( ([
       "grass" : "The long grass is quite matted here.",
    "clearing" : (:GetLong:),
      "pasture" : "The pasture lies to the south.",
  ({"bush", "bush"}) : "The bushes are small and prickly.",
   ({ "sapling", "saplings", "trees", "tree"}) : "These small trees are "
                       "scattered and there are not very many of them.",
           ]) );
  }
