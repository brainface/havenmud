/*  A path leading to the Gnomes Burrow, intesection to the first cavern */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("a path");

  SetLong("The worn path underfoot seems to lead to the north and the "
          "southeast.  Although, this particular point along the tunnel has "
          "widened and some caverns seem to be visible to the northeast.  "
          "Aside from that there isn't too much to see at this point along "
          "the tunnel.");

  SetSmell( ([
    "default"  :  "Very curious smells are prevalent here, although "
                  "you cannot distinguish them.",
  ]) );

  SetExits( ([
    "southeast"  :  ROOMLV1 + "/entrance",
    "north"      :  ROOMLV1 + "/path2",
    "northeast"  :  ROOMLV1 + "/cave1a",
  ]) );
  SetItems( ([
    ({ "worn path", "path" })  :
       "The path underfoot is worn from years of use, and yet free of debris "
       "as if someone maintains the path.",
    ({ "cavern", "caverns", "cave", "caves" })  :
       "There isn't much to see from here, but it looks larger than anything "
       "thus far into the caves.",
    ({ "debris" })  :
       "There is no debris here, the path is free of it!",
  ]) );
}
