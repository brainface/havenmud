//coded by Syra 8/97

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a hidden grove");
  SetDomain("Havenwood");
  SetLong("This grove is hidden among the tall trees and can't "
    "be seen from the pathway. There is a low canopy of trees "
    "that help to protect this area from both intrusion and the "
    "elements. The only way out is to the northeast. "
    "There also appears to be a section of matted grass in the "
    "southwest corner of the grove. It seems to be a favored sleeping "
    "area for some kind of creature.");
  SetItems( ([
    ({"grove", "hidden grove", "area"}) : (:GetLong:),
    ({"grass", "matted grass"}) : "This seems to be a sleeping "
        "area for some type of animal.",
             ({"hidden spot in havenwood","havenwood","wood",
               "woods","secluded spot","spot"}) : (:GetLong:),
             ({"tall trees","trees","tree"}) : "The trees "
               "encircle this secluded spot. ",
             ({"clearing"}):"There is a clearing some distance "
               "to the northeast.",
             ({"tight, low canopy of trees","low canopy in the trees",
               "canopy of trees","low canopy",
               "tight canopy","canopy","trees","tree"}):
               "Virtually nothing can filter through the tight, "
               "low canopy. ",
     ]) );
  SetExits( ([
             "northeast" : HWD_ROOM + "/trail2",
     ]) );
  SetInventory( ([ 
             HWD_NPC + "/tarandus" : 1,
     ]) );
  SetListen( ([
        "default" : "Silence reigns here. "
     ]) );

  }


/* Approved by Amelia on Fri Sep 12 00:18:38 1997. */
