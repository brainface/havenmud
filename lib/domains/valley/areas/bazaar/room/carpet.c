/* This is a booth where rugs are sold. A lucky customer might find a magic carpet for sale. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a carpet booth");
  SetLong("Here is a canopy-covered booth full of exotic "
     "rugs and carpets. Most of them have been imported from "
     "the far corners of Kailie. The rugs line the ground and "
     "some are stacked up in the back of the booth. Some "
      "picnic tables are visible to the west, and there seems "
     "to be some commotion to the north. Another booth is "
      "east of here.");
  SetItems( ([
   ({ "booth" }) : "It is made of a canvas canopy that is held up by four sturdy sticks in the ground.",
   ({ "rug", "rugs" }) : "There is a unique pattern on each hand-made rug.",
   ({ "carpet", "carpets" }) : "There is a unique pattern on each hand-made carpet.",
   ({ "canopy" }) : "The canopy is made from a pale striped canvas.",
   ({ "canvas" }) : "It has a pale striped pattern.",
   ({ "stack" }) : "There appears to be something behind the stack of rugs.",
  ]) );
  SetItemAdjectives( ([
   "booth" : ({ "canopy-covered" }),
   "rug" : ({ "exotic" }),
   "carpet" : ({ "exotic" }),
     "canopy" : ({ "canvas" }),
  ]) );

  SetSmell( ([
     "default" : "The air is filled with smells of food and incense.",
  ]) );
  SetListen( ([
     "default" : "Loud sounds of laughter are coming from the north."
  ]) );
  SetExits( ([
     "north" : BAZAAR_ROOM "tree",
     "east" : BAZAAR_ROOM "trinket",
     "west" : BAZAAR_ROOM "table2",
  ]) );
  SetInventory( ([ BAZAAR_NPC + "dahlia" : 1, ]) );
}
