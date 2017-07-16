/* This is an empty space where a booth used to be. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("an empty booth");
  SetLong("This booth is unoccupied. The lack of a tenant has "
     "caused the area to take on the look of a trash "
     "dump. There are half-eaten pieces of meat on the "
     "ground, the canvas is falling apart, and there is "
     "a trail of ants marching across the dirt.  There is a "
     "booth to the east, and to the south and west are "
     "grassy clearings.");
  SetSmell( ([
     "default" : "It smells like mildew here.",
  ]) );
  SetListen( ([
     "default" : "The sounds of laughter drift in from all around.",
  ]) );
  SetItems( ([
   ({ "meat" }) : "Some of the dropped meat has already been chewed on.",
   ({ "area" }) : "It looks like a dump.",
   ({ "booth" }) : "The dilapidated booth is falling apart. The canvas canopy is torn in several places.",
   ({ "canopy", "canvas" }) : "The stiff canvas canopy is torn in several places.",
   ({ "ant", "ants" }) : "A busy trail of ants works to carry away the meat.",

  ]) );
  SetItemAdjectives( ([
   "meat" : ({ "pieces of" }),
   "ants" : ({ "trail of" }),
  ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "juggle",
     "west" : BAZAAR_ROOM "stilt",
     "southwest" : BAZAAR_ROOM "tree",
     "east" : BAZAAR_ROOM "flowers",
  ]) );
}
