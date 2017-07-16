//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("On Temple Road");
  SetLong(
    "This broad avenue is lined with large statues of ancient rulers "
    "that have since their death become nearly deified, as well as "
    "the occasional well-tended incense tree. Monstrous stone idols "
    "of minor deities rise from the ground like ancient trees. The "
    "flagstones are flecked with bits of electrum and mica, giving "
    "the street a divine glint. A small bank stands to the west here."
    );
  SetItems( ([
    ({"statues", "statue"}) : 
    "The statues are somewhat defaced with the passage of time, but "
    "they are gigantic in size and very detailed.",
    ({"tree", "trees"}) : 
    "In such a climate, trees are rare. But these are beautiful and "
    "well tended. They exude a wonderful fragrance.",
    ({"stones", "flagstone", "flagstones" }) : 
    "The stones here are like any other roads, except that they "
    "sparkle.",
    ({ "bank" }) :
    "Perhaps one can trade for or entrust one's deben within.",
    ]) );
  SetEnters( ([
    "bank" : LISHT_ROOM "gnoll/bank",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/pr3",
    "south" : LISHT_ROOM "gnoll/tr2",
    ]) );
  SetSmell("The trees exude a sweet fragrance.");
}
