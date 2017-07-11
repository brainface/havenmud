/* This is a grassy hill. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a grassy hill");
  SetLong("This is a steep hill from where one can see all of the "
     "bazaar. There isn't a great deal of traffic through this area, "
     "as is apparent by the lush grass and beautiful flowers. A few "
     "oak trees similar to the very large tree in the center of the "
     "bazaar, only not quite as big, are here as well. From here "
     "one can see the shopping booths to the southeast, a large "
     "field of some sort to the southwest, and some various attractions "
     "to the south.");
  SetItems( ([
     ({ "hill" }) : (: GetLong :),
   ({ "bazaar" }) : "The colorful bazaar is full of booths, food and general "
     "merriment. At the center of the bazaar is a large tree.",
   ({ "grass" }) : "It is lush and green and dotted with beautiful flowers.",
   ({ "flower", "flowers" }) : "Sprinkled among the grass are daisies and jonquils.",
   ({ "field" }) : (: GetLong :),
   ({ "oak trees", "tree", "trees" }) :
     "These trees provide nice shade for someone that might want to sit down and rest.",
   ({ "large tree", "tree" }) : "This massive tree is in the center of the bazaar.",
   ({ "booth", "booths" }) :
     "In the east section of the bazaar you can see the canvas roofs of the shopping booths.",
   ({ "attraction", "attractions" }) :
     "There are some people performing various acts, a mud pit of some sort, "
     "and to the southwest is a large field for jousting contests.",
  ]) );
  SetItemAdjectives( ([
   "booth" : ({ "shopping" }),
   "field" : ({ "large" }),
   "attraction" : ({ "various" }),
   "hill" : ({ "steep" }),
   "grass" : ({ "lush" }),
   "flower" : ({ "beautiful" }),
   "trees" : ({ "oak", "smaller" }),
   "tree" : ({ "very", "large" }),
  ]) );
  SetSmell( ([
     "default" : "The smells of nature mingle with the smell of food coming from the south.",
  ]) );
  SetListen( ([
     "default" : "Birds are singing in the trees.",
  ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "pen",
  ]) );
}
