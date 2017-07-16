#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("in a small grove of trees");
   SetDayLong("Silver birch and white mulberry trees make a semi circle as if "
              "they were planted in that fassion.  The sky is almost completely "
              "blocked by leaves and branches that are intertwined with vines "
              "and nests.  Sunlight streaks through in small beams of light.  "
              "A cliff stands to the east and south making travel impossible.  "
              "The forest opens up to the north and west.  There is a small hut "
              "here with a small sign "
              "at the entrance.");
    SetNightLong("Tall trees surround and cover the area with their branches.  "
                 "The moon can be seen through the branches as it travels the "
                 "sky.  The ground is bare exept for ferns and random patches of "
                 "herbs.  There is a cliff surrounding the grove to the south and "
                 "east.  The forest continues to the north and west.  "
                 "There is a small hut standing here with a sign at the entrance.");
   SetItems( ([
                ({ "forest","grove","sunlight","moon","beams","beam","tree",
                   "trees" }) :
                   (: GetLong :),
                ({ "undergrowth" }) :
                   "The undergrowth consists only of ferns, "
                   "and randomly placed patches of herbs.",
                ({ "bare ground","ground","dirt","earth" }) :
                   "Rich brown earth provides fertilization for the "
                   "myriad of plants living here.",
                ({ "fiddlehead ferns","fiddlehead fern","ferns","fern" }) :
                   "Still curled into little balls at their tips, the "
                   "fiddlehead ferns rise out of the ground about a third of "
                   "a meter.",
                 ({ "white mulberry trees","trees","tree","mulberry","mulberries",
                   "white mulberry","white mulberries","white mulberry tree" }) :
                   "White mulberries hang at intervals along the branches of "
                   "the white mulberry trees, tempting and plump.",
                ({ "silver birch","birch","birches","silver birches" }) :
                   "Silver-white bark darkens to a brown-black at the base of "
                   "20 meter high birch trees.",
                 ({ "herb","herbs"  }) :
                   "There are herbs growing in small patches here.",
                ({ "sign" }) :
                   "There is a small sign at the door of the hut",
                ({ "hut","small hut" }) :
                   "The hut stands alone in the woods at the base of the cliff "
                   "with a thatched roof and polished log walls.  The entrance "
                   "is draped with a red cloth.",
                ({ "cloth","red cloth" }) :
                   "The cloth is draped over the entrance to the hut and is made "
                   "of fine red material.",
                ({ "entrance" }) :
                   "The entrance to the hut is covered with a red cloth.",
                ({ "cliff","cliff face" }) : 
                   "The cliff falls away with a sheer thirty meter drop.  Any "
                   "negligent step would mean certain death. The base of the "
                   "cliff is slammed constantly by the choppy surf of the ocean.",
                ({ "ocean","surf" }) :
                   "The ocean is a rich deep blue with white caps of waves sliding "
                   "into the rocks.",
                    ]) );

   SetRead( ([ "sign" : "Sitha's Herbs.", ]) );
   SetListen( ([
                 "default" : "The wind rustles the leaves above.",
            ]) );
   SetSmell( ([
                "default" : "The scent of brewing herbs fills the air.",
           ]) );
   SetInventory( ([
            FOREST_NPC + "seagull" : 3,
             ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "9,-3,0",
                "west" : AVERATH_ISLAND + "8,-4,0",
           ]) );
   SetEnters( ([ 
                "hut" : FOREST_ROOMS + "herbhut",
                "entrance" : FOREST_ROOMS + "herbhut",
             ]) );
 }
