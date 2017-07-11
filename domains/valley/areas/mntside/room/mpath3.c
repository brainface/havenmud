/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("the mountain path");
    SetLong("This is path up the side of a mountain. A few stones "+
      "can be seen scattered on the sides of the path. "+
      "A bit further up the path a small structure can barely be "+
      "made out. Further down the path can be seen a small group "+
      "of crude looking structures.");
    SetItems( ([
	({ "path" }) : "A worn path on the edge of the mountain.",
	({ "stone", "stones" }) : 
	"The few stones present are scattered around the sides of this path. "+
	"They appear to be of the same material as the mountain itself.",
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+
	"range. The snowcap is far above you.", 
	({ "structure", "small structure" }) : "At this distance the structure is "
	"too far away and too far above you to make out any details.",
	({ "structures","huts","crude structures","structure","crude structure",
	  "hut" }) : "The structures appear to be small dwellings on the next "+
	"plateau down the mountain.",
      ]) );
    SetClimate("arid");   
    SetExits( ([
	"northwest" : RMS+"mpath2",
	"southeast" : RMS+"mpath4",
      ]) );
    SetSmell( ([ 
	"default" : "The faint odor of smoke wafts up from the structures below.",
      ]) );
    SetInventory( ([ 
        NPC+"goat" : 1,
    	  NPC+"mdwarf" : random(2) + 1,
        NPC+"fdwarf" : random(2) + 1,
        	 ]) );
  SetDomain("Valley");
}
