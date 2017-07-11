#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dark lake");
    SetDomain("Crystal Reaches");
    SetLong(
      "Rock on the shoreline of the lake is pitted and badly "
      "damaged by the substance in the lake. Many of the rocks "
      "which are smooth still have rough, irregular surfaces where "
      "the lake has not yet touched. A few trees have collapsed into "
      "the substance and now bob gently producing slight "
      "ripples."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "Many of the trees are sick and some are dead.  They are being "
      "affected by some dark power which is at work on the entire "
      "forest.",
      ({"vegetation", "forest", "woods", "wood"})  :
      "The forest has been made very sick by an unseen force.  Most "
      "of the trees are slowly dying.",
      ({"ripple", "ripples"})  :
      "A few trees have fallen into the lake.  They bob gently in the "
      "substance and produce very faint ripples.",
      ({"branch", "branches"})  :
      "The tree branches lack leaves and are beggining to twist in a "
      "chaotic fashion.",
      "lake"  :  (: GetLong :),
      "shoreline"  :
      "The lake is slowly destroying the surrounding land.  Rocks that "
      "lie upon the shoreline are being dissolved slowly along with the "
      "earth itself.",
      ({"rocks", "rock"})  :
      "Puddles of the substance which the lake is composed "
      "of have formed pits in the rocks.  The rocks have been "
      "smooth and flattened by the destructive powers of the "
      "lake substance.",
      ({"shadow", "shadows"})  :
      "The haze of the lake prevents a perfect view of the "
      "shadows.  They seem to be steadily undulating with the "
      "substance, but at the same time they twist in an eratic "
      "fashion.",
      "substance"  :
      "The substance bears hardly any resemblance to water.  "
      "It emits an acrid scent and is thick and hazy.  Even though "
      "it stands perfectly still and calm, it seems to be slowly "
      "expanding the bounds of the lake with its corrosive "
      "nature.  Shadows linger in its depths.",
      ]) );
    SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "substance"    :  ({"acrid", "thick", "hazy", "calm", "corrosive",
        "still"}),
      "shadow"    :  ({"undulating", "twisting", "eratic", "hazy"}),
      "vegetation"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "rock"   :   ({"smooth", "smoothed", "pitted"}),
      "ripple"  :  "faint",
      "woods"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "branch"    :  ({"overlapping", "tree"}),
      "lake"   :  ({"unwholesome", "dark", "murky", "acrid"}),
      "shoreline"  : ({"rocky", "stoney"}),
    ]) );
    SetSmell( ([
      "default"  :  "A strong acrid stench hangs in the air.",
    ]) );
    SetListen( ([
      "default"  :  "The area is devoid of life.",
    ]) );
    SetExits( ([
      "northwest"  :  ROOMS + "/lake.c",
      "south"   :   ROOMS + "/stinky.c",
    ]) );
}
