#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("at the edge of the woods");
    SetLong("The trees are sparse here as a river flows down from the mountain "
      "and skirts the edge of the forest to the south.  The path forks "
      "here.  It continues alongside the river to the south.  To the east "
      "it disappears into the forest, and to the northwest it winds "
      "towards the mountains.");
    SetListen( ([ "default" : "The gurgle of the water rushing is heard."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	(: GetLong() :),
	({ "dense forest","forest","sparse trees","trees" }) :
	"The trees come to an end here.  More trees are visible to "
	"the east.",
	({ "many mountains","mountains","mountain" }) :
	"Many mountains border the forest to the west.",
	({ "flowing river","river" }) :
	"A river flows down the mountain and continues alongside "
	"the forest to the south."
      ]) );
    SetObviousExits("northwest, south, east");
    SetExits( ([
	"northwest" : F_ROOM "forest8",
	"south"     : F_ROOM "forest9",
	"east"      : F_ROOM "forest6"
      ]) );

}