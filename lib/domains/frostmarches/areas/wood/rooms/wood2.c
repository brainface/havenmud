/* a dark wood
   Ela 8/3/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();

  SetShort("a dark wood");

  SetDomain("FrostMarches");
  SetClimate("temperate");

  SetObviousExits("east, west, south, southeast, southwest");

  SetExits( ([
          "east" : WOOD_ROOMS + "wood1",
          "west" : WOOD_ROOMS + "wood3",
          "south" : WOOD_ROOMS + "wood5",
          "southeast" : WOOD_ROOMS + "wood6",
          "southwest" : WOOD_ROOMS + "wood4",
         ]) );

  SetLong("Shades of darkness spread sinister shadows over the "
          "wood. Little light penetrates the dense canopy "
          "above. Wickedly sharp briars grow abundantly and "
         "the oversized trees appear alive and threatening in "
         "the gloom. Dense brush litters the ground, making "
         "travel difficult. Stifling and creepy, the wood "
         "is altogether uninviting.");

  SetItems( ([
          ({"sinister darkness","darkness","shadow","shadows"}) :
              "Shadows blanket the wood in forbidding darkness.",
         ({"dense canopy","canopy"}) : "The trees form a dense "
              "canopy, shrouding the wood in shadows.",
          ({"light","sunbeam","sunbeams"}) : "A few single "
              "sunbeams make their way through the dense canopy "
              "above to the light the wood.",
         ({"sharp briar","briar","briars"}) : "These painfully sharp "
              "briars run wild and grow densely.",
        ({"wood","woods"}) : "The woods is shrouded in shadows.",
        ({"tree","trees"}) : "Massive trees appear monster-like "
             "in the darkness.",
         "gloom" : "Shadows blanket the wood in forbidding "
              "darkness.",
         ]) );

  SetSmell( ([
         "default" : "A pine-fresh aroma pervades the area.",
         ]) );
  SetListen( ([
         "default" : "The wind stirs through the wood.",
         ]) );
}
