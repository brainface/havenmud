#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("near the end of the woods");
    SetLong("The path here goes west and southeast.  The trees are not as dense "
      "here as they are to the east, and they thin out even more as the "
      "path continues futher to the west.  The mountain range to the west "
      "is clearly visible.");
    SetListen( ([ "default" : "A breeze rustles the leaves slightly."]) );
    SetItems( ([
	({ "winding path","forest path","small path",
	  "fork in the woods","fork","roughly-made path","path" }) :
	(: GetLong() :),
	({ "eastern road","distant road","road" }) :
	"A road running north and south can barely be made out to "
	"the east.",
	({ "dense trees","trees","tree","forest" }) :
	"To all sides, a number of trees are crowded together.",
	({ "snowcapped peaks","mountain range","peaks","mountains" }) :
	"A mountain range can be made out to the west of the "
	"forest."
      ]) );
    SetInventory( ([
	F_NPC "wolf" : 1
      ]) );
    SetObviousExits("west, southeast");
    SetExits( ([
	"west"      : F_ROOM "forest4",
	"southeast" : F_ROOM "forest2",
      ]) );

}
