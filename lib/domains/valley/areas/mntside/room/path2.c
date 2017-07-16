/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a path through the woods");
    SetLong("This is a faint path running through the pine forest surrounding "
      "Jidoor. The path is beginning to rise as it heads towards the "
      "foothills of "
      "the Crystal Reaches. The woods are beginning to thin out; the  "
      "trees are becoming smaller and the foliage thinner.");
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
	"east" : RMS + "path1",
	"northwest" : RMS + "path3",
      ]) );
    SetSmell( ([ 
	"default" : "The forest loam gently wafts from the surrounding trees.",
      ]) );
    SetInventory( ([
        NPC+"mdwarf" : random(2),
        NPC+"fdwarf" : random(2),
      ]) );
  SetDomain("Valley");
}
