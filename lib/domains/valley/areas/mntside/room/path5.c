/* Create by Aramuuk. 1998 */
#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
    room::create();
    SetShort("a path through the woods");
    SetLong("This is a faint path running through the pine forest which borders "
      "the Crystal Reaches. As the path approaches the foothills of the "
      "mountains it begins to rise. The woods are beginning to thin out; the  "
      "trees are becoming smaller and the foliage thinner.  The underbrush "
      "has become much thicker here.");
    SetItems( ([
	({ "path" }) : "This is a slightly worn path through the woods. It reminds you of an animal track.",
	({ "tree", "trees", "pine trees", "pines", "forest", "woods" }) :
	"The trees in this part of the forest are mainly pine, with a few birch and oaks thrown in.",
	({ "foothills", "foothill", "crystal reaches", "reaches", "mountain", "mountains" }) :
	"Glimpses of the mountains can be seen through the thining foliage. The snowcaps glitter like crystal shards.", 
	({ "underbrush" }) : "Small plants which grow close together and even closer to the ground.", 
	({ "foliage" }) : "The foliage has thinned enough to reveal glimpses of the mountains.",
      ]) );
  SetDomain("Valley");
    SetClimate("temperate");   
     SetInventory( ([
        NPC+"mdwarf" : random(3) + 2,
        NPC+"fdwarf" : random(3) + 2,
      ]) ); 
    SetExits( ([
	"southeast" : RMS+"path4",
	"northwest" : RMS+"path6",
      ]) );
}
