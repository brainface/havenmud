/* This is a small picnic area for carnival-goers to sit and eat or talk. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a picnic area");
  SetLong("This is a small area that has been set aside "
     "for people to sit down and eat, or just to chat. "
     "There are four wooden picnic tables with benches, "
     "and a metal barrel for throwing trash in. There is "
     "a grassy clearing to the east and the food booth "
     "is back to the south. A tall fence runs along the "
     "west edge of the picnic area.");
  SetItems( ([
   ({ "table", "tables" }) : "The unpolished tables are a little weather-worn. Some little drawings have been etched into the surface.",
   ({ "bench", "benches" }) : "They are slightly wobbly, but suitable for sitting on.",
   ({ "fence" }) : "The tall fence stretches for several feet.",
   ({ "drawing", "drawings" }) : "The drawing is of a dragon.",
   ({ "barrel" }) : "Some flies are buzzing around it.",
({ "flies" }) : "The little flies are swarmed around the smelly trash.",
  ]) );
  SetItemAdjectives( ([
   "table" : ({ "four", "wooden", "picnic" }),
   "fence" : ({ "tall" }),
   "barrel" : ({ "metal" }),
  ]) );
  SetSmell( ([
     "default" : "Strong smells of food waft through the air.",
  ]) );
  SetListen( ([
     "default" : "You hear laughter all around and some animal noises from the west.",
  ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "food",
     "east" : BAZAAR_ROOM "stilt",
     "southeast" : BAZAAR_ROOM "tree",
  ]) );
}
