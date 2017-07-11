#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("beside a large mountain");
    SetLong("The large mountain directly to the west blocks much of the sky "
      "from view.  It seems to be one of the larger ones in the mountain "
      "range.  An opening into the mountain can be seen nearby.  The path "
      "disappears into this cave.  To the northeast, the path winds "
      "towards a river at the edge of the forest.");
    SetListen( ([ "default" : "All is mysteriously silent here."]) );
    SetSmell( ([ "default" : "The breeze carries an awful smell out from near "
	"the mountain." ]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	"The path comes from the northeast and enters the cave.",
	({ "thickening forest","forest","sparse trees","trees",
	  "tree" }) :
	"To the east, trees are visible in increasing numbers.",
	({ "large mountain","mountain range","mountains","mountain",
	  "foot of mountain" }) :
	(: GetLong() :),
	({ "flowing river","river","forest's edge","edge",
	  "forest edge" }) :
	"To the northeast, a river can be made out flowing along "
	"the edge of the forest.",
	({ "mountain opening","opening","cave" }) :
	"An opening in the side of the mountain leads to a cave.",
	({ "blocked sky","sky" }) :
	"The sky is barely visible due to the presence of a large "
	"mountain."
      ]) );
    SetInventory( ([
	F_NPC "goblin" : 2
      ]) );
    SetObviousExits("northeast");
    SetExits( ([
	"northeast" : F_ROOM "forest9"
      ]) );
    SetEnters( ([
	"cave"     : F_ROOM "cave3"
      ]) );
}
