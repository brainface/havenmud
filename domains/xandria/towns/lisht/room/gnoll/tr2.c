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
    "The broad avenue, lined with large statues and tiny incense "
    "trees, continues southward. The paving is still flecked with "
    "sparkling minerals that reflect the sunlight like a thousand "
    "brilliant mirrors. One can easily make out the temple standing "
    "to the south, and the road leads also northward to the palace. "
    );
  SetItems( ([
    ({"statues", "statue"}) : 
    "The statues are somewhat defaced with the passage of time, but "
    "they are gigantic in size and very detailed.",
    ({"tree", "trees"}) : 
    "In such a climate, trees are rare. But these are beautiful and "
    "well tended. They exude a wonderful fragrance.",
    ({"stones", "flagstone", "flagstones", "paving" }) : 
    "The stones here are like any other roads, except that they "
    "sparkle.",
    ({"temple" }) : 
    "The temple complex stands in the south, from here one can only "
    "discern that it is expansive.",
    ]) );
  SetExits( ([
   "north" : LISHT_ROOM "gnoll/tr1",
   "south" : LISHT_ROOM "gnoll/tr3"
    ]) );
  SetSmell("The trees exude a sweet fragrance.");
}
