// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("inside a well-lit forest");
   SetDayLong("Golden sunrays caress the undergrowth of ferns, devil's clubs, "
              "and blueberry bushes.  A plethora of white mulberry trees "
              "decorate the area, shrouded with a speckling of oaks and "
              "birch trees.  The forest fades into greater darkness to the "
              "east and south, while opening up to the north and west.");
   SetNightLong("Moonbeams slip through a light layer of leaves to "
                "tickle the undergrowth of ferns, devil's clubs, and "
                "blueberry bushes.  Oaks and birch trees grow above a "
                "conglomeration of white mulberries.  Darkness fills the "
                "forest to the east and south, while open spaces peak "
                "between tree trunks to the west and north.");
   SetItems( ([
                ({ "forest","golden sunrays","sunray","rays","sunrays",
                   "moonbeams","moonbeam","beams","beam","ray" }) :
                   (: GetLong :),
                ({ "undergrowth" }) :
                   "The undergrowth consists primarily of ferns, devil's "
                   "clubs, and blueberry bushes.  Patches of bare "
                   "ground remain visible between the bushes.",
                ({ "bare ground","ground","dirt","earth" }) :
                   "Rich brown earth provides fertilization for the "
                   "myriad of plants living here.",
                ({ "fiddlehead ferns","fiddlehead fern","ferns","fern" }) :
                   "Still curled into little balls at their tips, the "
                   "fiddlehead ferns rise out of the ground about a third of "
                   "a meter.",
                ({ "devil's clubs","devil's club","clubs","club" }) :
                   "Light brown bark conceals the prickly spines of the "
                   "devil's club.  At the top, large leaves with thorns "
                   "along the veins flop in the breeze, with a sprig of "
                   "brilliant red berries in the center.",
                ({ "blueberry bushes","bushes","bush","blueberry bush" }) : 
                   "The blueberry bushes sprout small circular leaves with a "
                   "tinge of blue.  Berries grow at random points along the "
                   "branches.",
                ({ "white mulberry trees","trees","tree","mulberry","mulberries",
                   "white mulberry","white mulberries","white mulberry tree" }) :
                   "White mulberries hang at intervals along the branches of "
                   "the white mulberry trees, tempting and plump.",
                ({ "silver birch","birch","birches","silver birches" }) :
                   "Silver-white bark darkens to a brown-black at the base of "
                   "20 meter high birch trees.",
                ({ "oak trees","oak","trees","tree","oak" }) :
                   "The oak trees mingle with the birches above the mulberries "
                   "and undergrowth.",
           ]) );
   SetListen( ([
                 "default" : "The wind rustles the leaves above.",
            ]) );
   SetSmell( ([
                "default" : "The aroma of fresh air flutters through the forest.",
           ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "6,-2,0",
                "west" : AVERATH_ISLAND + "5,-3,0",
                "south" : AVERATH_ISLAND + "6,-4,0",
                "east" : AVERATH_ISLAND + "7,-3,0",
           ]) );
//  SetInventory!
   SetInventory( ([
                    FOREST_NPC + "hunter" : 2,
               ]) );
}
