#include <lib.h>
#include "../tairi.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("along the Chrysanthemum Path");
  SetExits( ([
    "west" : "path6",
    "east" : "path8",
    ]) );
  SetLong("The path leads to the east and west here. To the east "
          "lies the Taisoka Temple, while off to the west is "
          "the center of Tairi. The path is lined with flowers here "
          "which bloom in the always pleasant valley lands of Tairi.");
  SetItems( ([
    ({ "flower", "flowers", "chrysanthemum", "chrysanthemums" }) :
            "The flowers are a lovely shade of purple.",
    "temple" : "The Temple of Taisoka is just east of here.",
    ({ "town", "center", "tairi", }) :
    	      "The center of Tairi is east along the path.",
    ({ "path", "road" }) :
    	      "The dirt path is lined with chrysanthemums and heads "
    	      "east into Tairi center and west towards the Temple of "
    	      "Taisoka.",  
    ({ "valley", "mountain", "mountains" }) :
    	      "The town of Tairi sits in a valley in the Tai mountain range.",
    ]) );
  SetItemAdjectives( ([
    "flower"  : ({ "purple" }),
    "town"    : ({ "center", "tairi" }),
    "path"    : ({ "dirt" }),
    "valley"  : ({ "pleasant" }),
    "town"    : ({ "tairi" }),
    "temple"  : ({ "taisoka" }),
    ]) );    
  SetSmell( ([
    "flower"  : "The flowers smell wonderfully light.",
    "default" : "The scent of the flowers is a pleasant backdrop.",
    ]) );
  SetListen( ([
    "default" : "The path is serenely quiet.",
    ]) );
}


