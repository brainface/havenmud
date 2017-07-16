/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("the mountain path");
    SetLong("This is path up the side of a mountain. The terrain around "+
      "the path is fairly barren except a few hardy shrubs and "+
      "grasses which are growing in scattered clumps. "+
      "Just to the southwest is a small group "+
      "of crude looking structures.");
    SetItems( ([
	({ "path" }) : "A worn path on the edge of the mountain.",
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+
	"range. The snowcap is far above you.", 
	({ "structures","huts","crude structures","structure","crude structure",
	  "hut" }) : "The structures are a group of small dwellings on the next "+
	"plateau down the mountain.",
	({ "shrub", "shrubs" }) : "The shrubs are small and grow close to the "+
	"ground. Each branch has a lot of small, flat, thick leaves which "+
	"appear very durable.",
	({ "grass", "grasses" }): "The grasses grow in small clumps wherever "+
	"they can find purchase in the rocky soil. Enough of the grasses "+
	"put together would form a nice mattress.",

      ]) );
    SetClimate("arid");   
    SetExits( ([
	"northwest" : RMS+"mpath3",
	"southwest" : RMS+"mpath5",
      ]) );
    SetInventory( ([
        NPC+"guards" : random(2)+3,
      ]) );
  SetDomain("Valley");
}
