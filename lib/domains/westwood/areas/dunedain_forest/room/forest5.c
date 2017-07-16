#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Estergrym");
    SetShort("next to the mountain");
    SetLong("Directly to the west a large mountain looms high above the ground. "
      "The path continues into the mountain to cave-like opening that can "
      "clearly be made at its foot.  To the east, the beginnings of a "
      "dense forest can be made out.  The path continues southeast into "
      "this forest.");
    SetListen( ([ "default" : "Rumbling can be heard from the mountain."]) );
    SetSmell( ([ "default" : "An awful stench comes from near the mountain."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	(: GetLong() :),
	({ "dense forest","forest","beginnings of forest","trees"
	  "beginnings" }) :
	"Trees can be seen coming together to form a dense forest "
	"to the east.",
	({ "large mountain","looming mountain","mountain" }) :
	"A large mountain stands to the east.  Crevices that may "
	"be used as shelter jut into it.",
	({ "cave-like opening","opening","dark foreboding cave",
	  "dark cave","foreboding cave","foot of the mountain",
	  "foot","cave" }) :
	"A dark foreboding cave opens into the foot of the mountain."
      ]) );
    SetInventory( ([
	F_NPC "weakgoblin1" : 1,
	F_NPC "weakgoblin2" : 1
      ]) );
    SetObviousExits("southeast");
    SetExits( ([
	"southeast" : F_ROOM "forest4",
      ]) );
    SetEnters( ([
	"cave"      : F_ROOM "cave1"
      ]) );

}