#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("alongside the river");
    SetLong("A river springs from the mountains to the west and continues "
      "southward alongside the forest's edge.  To the east, the forest "
      "thickens, while to the west the mountain range stands.  The path "
      "follows the river to the north and nears a large mountain to the "
      "southwest.");
    SetListen( ([ "default" : "The movement of the water is all that can be "
	"heard."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	(: GetLong() :),
	({ "thickening forest","forest","sparse trees","trees" }) :
	"To the east, trees are visible in increasing numbers.",
	({ "large mountain","mountain range","mountains","mountain" }) :
	"One of the large mountains of the mountain range stands "
	"nearby to the southwest.",
	({ "flowing river","river","forest's edge","edge" }) :
	"A river flows from the north alongside the edge of the "
	"forest."

      ]) );
    SetObviousExits("southwest, north");
    SetExits( ([
	"southwest" : F_ROOM "forest10",
	"north"     : F_ROOM "forest7"
      ]) );
}