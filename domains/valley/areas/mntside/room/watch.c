#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
  SetDomain("Valley");
    SetShort("the end of the path");
    SetLong("This is the end of the mountain path. Large and small stones "+
      "have been piled here to form both a bench and a crude shelter "+
      "from the elements. From this vantage point you can observe "+
      "all of the path which leads from Jidoor to the small gathering "+
      "of huts below.");
    SetItems( ([
	({ "path" }) : "A worn path on the edge of the mountain.",
	({ "bench","crude bench","shelter","crude shelter" }) : 
	"All type of stones have been fitted together to form both the "+
	"bench and the shelter. The craftmanship is incredible!",
	({ "mountain" }) : "One of they mountains in the Crystal Reaches "+
	"range. The snowcap is far above you.", 
	({ "stone","stones","large stone","large stones","small stone",
	  "small stones" }): "The stones all appear to be worked by the hands "+
	"of skilled craftsmen and appear to come from the sourrounding slopes.",
      ]) );
    SetClimate("arid");
    SetExits( ([
	"down" : RMS+"mpath1",
      ]) );
    SetListen( ([
	"default" : "You hear the wind blowing over the Crystal Reaches.",
      ]) );
    SetInventory( ([
	NPC+"mdwarf" : random(4)+4,
      ]) );
}
/* Create by Aramuuk. 1998 */
