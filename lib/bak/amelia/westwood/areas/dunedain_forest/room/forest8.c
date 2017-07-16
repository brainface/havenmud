#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("at the foot of a mountain");
    SetLong("Immediately to the west a large mountain rises into the sky.  To "
      "the east, a river flows along the edge of a gradually thickening "
      "forest.  A small path emerges from an indentation at the foot of "
      "the mountain, revealing a cave-like dwelling of some sort.  The "
      "path continues to the southeast, and recedes into the forest.");
    SetListen( ([ "default" : "All is mysteriously silent here."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path",
	  "mountain foot","foot" }) :
	(: GetLong() :),
	({ "thickening forest","forest","sparse trees","trees" }) :
	"To the east, trees are visible in increasing numbers.",
	({ "large mountain","mountain","cave-like dwelling",
	  "dwelling","cave","indentation" }) :
	"A cave can be seen in the large mountain directly to the "
	"west.",
	({ "flowing river","river" }) :
	"A river flows down the mountain and continues eastward."
      ]) );
    SetInventory( ([
	F_NPC "goblin" : 1,
	F_NPC "weakgoblin1" : 1,
	F_NPC "weakgoblin2" : 1
      ]) );
    SetObviousExits("southeast");
    SetExits( ([
	"southeast" : F_ROOM "forest7",
      ]) );
    SetEnters( ([
	"cave" : F_ROOM "cave2",
      ]) );

}