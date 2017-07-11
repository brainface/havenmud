/* a dark wood
  Ela 10/10/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a dark wood");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("east, west, north, northeast, northwest");
  SetExits( ([
         "east" : WOOD_ROOMS + "wood6",
         "west" : WOOD_ROOMS + "wood4",
         "north" : WOOD_ROOMS + "wood2",
         "northeast" : WOOD_ROOMS + "wood1",
         "northwest" : WOOD_ROOMS + "wood3",
         ]) );
  SetLong("Shades of darkness spread sinister shadows over the "
         
	"wood. The dense canopy overhead allows little light "
         "light to penetrate. Wickedly sharp briars grow "
         "abundantly, crowding the forest floor. The "
         "oversized trees appear alive and threatening in the "
         "gloom.");
  SetItems( ([
         ({"sinister darkness","darkness","shadow","shadows"}) : 
             "Shadows blanket the wood in forbidding darkness.",
         ({"dense canopy","canopy"}) : "The trees form a dense "
             "canopy, shrouding the wood in shadows.",
         ({"light","sunbeam","sunbeams"}) : "A few single "
            "sunbeams make their way through the dense canopy "
             "above to light the wood.",
         ({"sharp briar","briar","briars"}) : "These painfully sharp "
             "briars run wild and grow densely.",
         ({"wood"}) : "The wood is shrouded in shadows.",
         ({"trees","tree"}) : "Massive trees appear monster-like "
            "in the darkness.",
         "gloom" : "Shadows blanket the wood in forbidding " 
             "darkness.",
        ]) );
  SetSmell( ([
        "default" : "A pine-fresh aroma pervades the area.", 
        ]) );
  SetListen( ([
        "default" : "The rusling of leaves by unseen creatures breaks "
                   "the silence.",
       ]) );
  SetInventory( ([
     WOOD_NPC + "owl" : 1,
      ]) );
}
