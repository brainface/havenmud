#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("in the midst of the forest");
    SetLong("Trees surround the path to all sides.  Although not quite as dense "
      "as it is to the east, the forest still makes for an unfriendly "
      "atmosphere.  A path cuts through the woods to the west and to the "
      "northeast.  To the west, the trees clear up and mountains can be "
      "seen.  To the northeast, the trees thicken.");
    SetListen( ([ "default" : "Only the rustling of the leaves is heard."]) );
    SetSmell( ([ "default" : "A pleasant breeze carries the smell of trees."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	(: GetLong() :),
	({ "dense forest","forest","beginnings of forest","trees"
	  "unfriendly atmosphere","atmosphere","wary aura","aura" }) :
	"The multitude of trees form a densely-wooded forest "
	"within which pervades a wary aura.",
	({ "mountains","mountain" }) :
	"To the west of the trees, mountains can be made out."
      ]) );
    SetInventory( ([
	F_NPC "bear" : 1
      ]) );
    SetObviousExits("west, northeast");
    SetExits( ([
	"northeast" : F_ROOM "forest2",
	"west"      : F_ROOM "forest7"
      ]) );

}
