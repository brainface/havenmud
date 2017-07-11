
/*beach
  Zara 7/29/98
*/

#include <lib.h>
#include <domains.h>
#include "../acove.h"
inherit LIB_ROOM;

static void create() {
 room::create();
  SetShort("a deserted beach");
  SetClimate("temperate");
  SetExits( ([
        "south" : ACOVE_ROOMS + "cove4",
        "north" : ACOVE_ROOMS + "cove2",
        "southwest" : INNERSEA_VIRTUAL "ocean/-13,1",
         ]) );
  SetLong("The sandy white beach stretches "
        "out as far as the eye can see.  Softly rolling "
        "dunes partially conceal what appears to be an old "
        "weathered shipwreck ahead.  It is tilted to one "
       "side and appears to have been in its present "
        "resting place for many years.  The beach appears "
        "deserted.");
  SetItems( ([
        "beach" : "The beach appears to be deserted.",
        ({ "dune", "dunes" })  : "The dunes vary in size and cover "
                                 "much of this part of the beach .",
        "shipwreck" : "This shipwreck looks as if it has been "
                      "here for quite some time. ",
        "place" : "The place where the wreck lies is tucked "
                  "between two sand dunes. ",
        ]) );
  SetItemAdjectives( ([
    "beach" : ({"white","deserted","sandy"}),
    "dunes" : ({"rolling","soft"}),
    "shipwreck" : ({"weathered","old"}),
     ]) );


}

