#include <lib.h>
#include "../forest.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetDomain("Estergrym");
    SetClimate("temperate");
    SetShort("at the end of the woods");
    SetLong("Only a few small trees are scattered here and there and the grass "
      "is much sparser here than it is to the east.  Further to the east "
      "the trees and greenery come together to form a dense forest.  To "
      "the west, a large mountain looms.  Dark crevices can be made out "
      "on the sides of the mountain.  The path curves northwest towards "
      "the mountain and east towards the forest.");
    SetListen( ([ "default" : "All is strangely silent here."]) );
    SetItems( ([
	({ "winding path","forest path","small path","path" }) :
	(: GetLong() :),
	({ "small scattered trees","small trees",
	  "scattered trees","small tree","tree","dense forest"
	  "forest","greenery" }) :
	"The trees and grass are quite sparse here, but get denser "
	"further to the east.",
	({ "large mountain","looming mountain","mountain",
	  "dark crevices","crevices","shelter" }) :
	"A large mountain stands to the east.  Crevices that may "
	"be used as shelter jut into it."
      ]) );
    SetObviousExits("northwest, east");
    SetExits( ([
	"northwest" : F_ROOM "forest5",
	"east"      : F_ROOM "forest3",
      ]) );

}