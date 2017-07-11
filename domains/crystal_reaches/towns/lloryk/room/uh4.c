#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a road leading through the Shire");
  SetLong("The road continues on to the north and south from here. "
          "To the south, the road runs in front of the village hall "
          "and the Eclat Temple. The rolling hills of the Shire "
          "spread out to the west, and the towering peaks of the "
          "Crystal Reaches loom over the eastern horizon. Two buildings "
          "sit side by side along the eastern side of the road; one "
          "seems to be a local trade office and the other the local "
          "post office."
    );
  SetItems( ([ 
    ({ "hill", "hills" }) : "The hills of the Shire are good for farming.",
    ({ "post office", "building", "office", }) :
                        "The Shire Post office is where all "
                        "mail and parcels arrive in Lloryk.",
    ({"bank", "commissariat", "office", "building", }) :
                        "The Trade Commisar's office is where all "
                        "inter-city commerce is regulated from.",
    ({ "temple" }) : "The Eclat Temple is off to the south.",
    ({ "reaches", "peaks" }) : "The Crystal Reaches are a vast mountain "
                        "range that rises to the east.",
     ({ "hall" }) : "The village hall is a small wooden building "
                    "which lies to the south.",
    ]) );
  SetItemAdjectives( ([
    "reaches" : ({ "crystal", "towering", }),
    "post office"    : ({ "post", }),
    "bank"    : ({ "trade", }),
    "hill"    : ({ "rolling", }),
    "hall"    : ({ "village" }),
    ]) );
  SetInventory( ([
    ]) );
  SetExits( ([
    "north" : LLORYK + "room/uh3",
    "south" : LLORYK + "room/uh5",
     ]) );    
  SetEnters( ([
    "post office" : LLORYK "room/post",
    "bank" : LLORYK "room/bank",
    ]) );
  SetListen( ([
    "default" : "From the farms to the west, the sound of animals can be heard.",
    ]) );
  SetSmell( ([
    "default" : "The smells of local farming and fertilization faintly taint the air.",
    ]) );
}
