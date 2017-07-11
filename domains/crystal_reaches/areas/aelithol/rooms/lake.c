#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a dark lake");
    SetDomain("Crystal Reaches");
    SetLong(
      "A murky lake of a thick, acrid substance is among "
      "the many diseased trees. Its dark depths are completely "
      "still except for the occasional drop of moisture falling "
      "from from an overhanging branch. Though the substance "
      "has no discernable color, shadows linger heavily on the "
      "bottom."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "Many of the trees are sick and some are dead.  They are being "
      "affected by some dark power which is at work on the entire forest.",
      ({"vegetation", "forest", "woods", "wood"})  :
      "The forest has been made very sick by an unseen force.  "
      "Most of the trees are slowly dying.",
      ({"branch", "branches"})  :
      "The tree branches lack leaves and are beggining to twist in a "
      "chaotic fashion.",
      "lake"  :  (: GetLong :),
      "shoreline"  :
      "The lake is slowly destroying the surrounding land.  Rocks that "
      "lie upon the shoreline are being dissolved slowly along with the "
      "earth itself.",
      "substance"  :
      "The substance bears hardly any resemblance to water.  "
      "It emits an acrid scent and is thick and hazy.  Even though "
      "it stands perfectly still and calm, it seems to be slowly "
      "expanding the bounds of the lake with its corrosive "
      "nature.  Shadows linger in its depths.",
      ({"shadow", "shadows"})  :
      "The haze of the lake prevents a perfect view of the "
      "shadows.  They seem to be steadily undulating with the "
      "substance, but at the same time they twist in an eratic "
      "fashion.",
      "rocks"  :
      "Puddles of the substance which the lake is composed of have "
      "formed pits in the rocks.  The rocks have been smooth "
      "and flattened by the destructive powers of the lake substance.",
    ]) );
    SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "substance"    :  ({"acrid", "thick", "hazy", "calm", "corrosive",
        "calm"}),
      "shadow"    :  ({"undulating", "twisting", "eratic", "hazy"}),
      "branch"    :  "overlapping", 
      "lake"   :  ({"unwholesome", "dark", "murky", "acrid"}),
      "shoreline"  : ({"rocky", "stoney"}),
    ]) );
    SetSmell( ([
     "default"  :  "A strong acrid stench hangs in the air.",
    ]) );
    SetListen( ([
      "default"  :  "It is quiet.",
    ]) );
    SetExits( ([
      "southeast"  :  ROOMS + "/evendeeper.c",
      "west"  :  ROOMS + "/sunken.c",
    ]) );
}
