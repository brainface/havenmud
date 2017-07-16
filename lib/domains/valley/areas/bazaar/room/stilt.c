/* This is a grassy clearance where a man on stilts is performing. */
#include <lib.h>
#include "../bazaar.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("temperate");
  SetDomain("Valley");
  SetShort("a clearing");
  SetLong("This is a grassy clearing just north of a huge "
     "oak tree. To the west you see a few tables and there "
     "are several booths east of here. The grass, although "
     "thick, has been trampled by the traffic of passers-by.");
  SetItems( ([
   ({ "clearing" }) : "The thick grass in this small clearing has been trampled by all the traffic.",
   ({ "tree" }) : "This massive tree would be visible for miles around.",
   ({ "grass" }) : "It has been trampled. There is a small caterpillar crawling around on the grass.",
   ({ "caterpillar" }) : "It is green with red spots.",
  ]) );
  SetItemAdjectives( ([
   "clearing" : ({ "grassy" }),
   "tree" : ({ "huge", "oak" }),
   "grass" : ({ "thick", "trampled" }),
   "caterpillar" : ({ "small" }),
  ]) );
  SetSmell( ([
     "default" : "There is a strong scent of meat being cooked."
  ]) );
  SetListen( ([
     "default" : "You hear laughter coming from all around."
    ]) );
  SetInventory( ([ BAZAAR_NPC + "stiltman" : 1, ]) );
  SetExits( ([
     "south" : BAZAAR_ROOM "tree",
     "east" : BAZAAR_ROOM "empty",
     "west" : BAZAAR_ROOM "table1"
  ]) );
}
