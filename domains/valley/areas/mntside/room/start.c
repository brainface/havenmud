
/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
  SetDomain("Valley");
    SetShort("a path through the woods");
    SetLong("This is a faint path running into a pine forest surrounding "+
      "Jidoor. It appears as if the path heads towards the foothills of "
      "the Crystal Reaches. The woods are somewhat gloomy due to the "
      "thick foliage.");
    SetItems( ([
	({ "path" }) : "This is a slightly worn path through the woods. It reminds you of an animal track.",
	({ "tree", "trees", "pine trees", "pines", "forest", "woods" }) :
	"The trees in this part of the forest are mainly pine, with a few birch and oaks thrown in.",
	({ "foothills", "foothill", "crystal reaches", "reaches" }) :
	"The foothills of the Crystal Reaches are obscured by distance.", 
	({ "foliage" }) : "The leaves and needles make for a thick covering",
      ]) );
    SetClimate("temperate");
    SetExits( ([
        "east" : "/domains/valley/virtual/valley/0,35",
	"west" : RMS+"path1",
      ]) );
    SetSmell( ([ 
	"default" : "The forest loam gently wafts from the surrounding trees.",
      ]) );
    SetListen( ([
	"default" : "The sounds of Jidoor can be heard faintly in the distance.",
      ]) );
}
