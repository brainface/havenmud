/* This is the site of the jousting contests. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a jousting field");
  SetLong("This long, narrow field is separated lengthwise "
     "by a long fence. It looks as if it would be a suitable "
     "place for a jousting contest. There are some stables at "
     "the north end of the field. A few benches have been placed "
     "off to the side so that one can sit and watch to see who "
     "will win. A booth is just east of here.");
  SetItems( ([
   ({ "field" }) : (: GetLong :),
   ({ "fence" }) : "This simple wooden fence stretches across the field, running north to south. "
     "It divides the field into two equal, narrow parts.",
   ({ "stable", "stables" }) : "It looks as if they would hold several horses.",
   ({ "bench", "benches" }) : "These wooden benches have been placed all along the east side "
     "of the field for the spectators to sit on.",
   ({ "booth" }) : "The ticket booth is back to the east.",
  ]) );
  SetItemAdjectives( ([
   "field" : ({ "long", "narrow" }),
   "fence" : ({ "long" }),
   "bench" : ({ "few", "wooden" }),
  ]) );
  SetSmell( ([
     "default" : "It smells like horses here.",
  ]) );
  SetListen( ([
     "default" : "Loud laughter and shouting rings in the air.",
  ]) );
SetExits( ([
     "east" : BAZAAR_ROOM "bet",
  ]) );
}
