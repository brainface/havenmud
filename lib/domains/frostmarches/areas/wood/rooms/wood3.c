/* faerie ring
   Ela 10/6/98
*/

#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;


static void create() {
  room::create();
  SetShort("a quiet grove");
  SetDomain("FrostMarches");
  SetClimate("temperate");
  SetObviousExits("east, south, southeast");
  SetExits( ([
        "east" : WOOD_ROOMS + "wood2",
        "south" : WOOD_ROOMS + "wood4",
        "southeast" : WOOD_ROOMS + "wood5",
        ]) );
  SetNoClean(1);
  SetLong("The dense curtain of leaves and foilage of the "
          "surrounding trees enclose this small grove. "
          "Mushrooms of enchanted proportions grow abundantly "
          "around a well worn circle near the center of the "
          "grove. The circle, a faerie ring, has wild flowers " 
         "blossoming in vibrant colors in its center. The ring "
         "itself radiates the shimmering luster of faerie magic, "
        "a warning for the unwary who might stumble within its "
       "boundaries.");
  SetItems( ([
         ({"tree","trees"}) : "Massive trees grow in a decidedly "
                    "circular formation, secluding the grove "
                    "from the rest of the forest.",
         ({"curtain","leaf","leaves","foilage"}) : "The trees "
                    "form a dense curtain overhead and alongside "
                    "the grove.",
         ({"center","path","circle","ring"}) : "This appears "
                   "to be a legendary faerie ring. The "
                  "distinctive shimmer of faerie magic "
                  "is evident. It would appear easy "
                 "for anyone unwary enough to enter it.",
         ({"mushroom","mushrooms"}) : "Beautiful 'sitting-stool' "
                    "mushrooms seem to flourish here.",
        ({"wildflowers","wildflower","flowers","flower"}) : 
                   "The varied growth of flowers in the grove "
                  "add color and fragrance to this enchanted area.",
        "grove" : "The grove appears to be a secluded, enchanted "
                    "area.",
       "ground" : "A strange light seems to shimmer lingeringly "
                   "amongst the mushrooms and flowers.",
         "light" : "A strange, enchanted light lingers faintly here.",
         ]) );
  SetInventory( ([
        WOOD_NPC + "faeboy" : 1,
         ]) );
  SetEnters( ([
      ({"ring","faerie ring","circle"}) : WOOD_ROOMS + "wood3.5",
     ]) );
  SetSmell( ([
      "default" : "A pine-fresh aroma pervades the area.",
        ]) );
  SetListen( ([
      "default" : "The wind whistles whimsically.",
      ]) );
}
