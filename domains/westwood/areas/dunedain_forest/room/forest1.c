#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("a path through the woods");
    SetLong("The path continues to wind through the dense forest.  Trees "
      "cover every inch of the ground and make it difficult to see "
      "much else.  The only opening in the trees is made by the "
      "path, which continues to wind deeper into the forest to the "
      "west and towards a road to the east.  In the distance, the "
      "white peaks of a mountain range can be seen over the high "
      "trees of the forest.");
    SetSmell( ([  "default" : "The damp smell of the woods is everywhere."]) );
    SetListen( ([ "default" : "The sounds of birds and other critters is "
        "heard."]) );
    SetItems( ([
        ({ "winding path","forest path","small path",
          "roughly-made path","path" }) :
        (: GetLong() :),
        ({ "eastern road","road" }) :
        "A road running north and south can barely be made out to "
        "the east.",
        ({ "dense forest","dense trees","trees","tree","forest" }) :
        "To all sides, a number of trees are crowded together in "
        "a very dense forest.",
        ({ "western forest","small path","forest","path" }) :
        "A small path winds through the forest to the west.",
        ({ "white peaks","mountain range","peaks","mountains" }) :
        "A mountain range can be made out to the west of the "

        "forest."
      ]) );
    SetInventory( ([
      ] ));
SetExits( ([
    "east" : "/domains/westwood/virtual/westwood/0,20",
    "west"   : F_ROOM "forest2"
  ]) );
}
