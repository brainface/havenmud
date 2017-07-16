#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("outer edges of a forest");
    SetDomain("Crystal Reaches");
    SetLong(
      "Trees surround you, and no good trail can be made out. "
      "Vines hang from tree branches and grow upon the "
      "ground. The forest does not seem very healthy at "
      "all. The branches of the largest trees cross over "
      "each other and create a thick canopy. Bushes "
      "surround the trees, but become more scarce as "
      "the density of the forest increases to the east."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "Many small trees once grew here, but are now rotten as is the "
      "rest of the area.",
      ({"bush", "bushes"})  :
      "Small bushes surrounding the trees become rare to the east.",
      ({"vegetation", "forest", "woods", "wood"})  :
      "The forest has been made very sick by an unseen force.  "
      "Most of the trees are slowly dieing.", 
      ({"plants", "brush", "underbrush"})   :
      "The dry shells of a prospering population of plants is all that "
      "remains of a once healthy area.",
      ({"vine", "vines"})  :
      "Fuzzy vines loop around trees and hang from their branches. ",
      ({"branch", "branches"})  :
      "Tree branches overlap in the canopy and are tangled with vines.",
      "canopy"  :
      "The branches of the trees overlap forming a thick canopy "
      "above the forest floor.",
    ]) );
   SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "bush"   :  "small",
      "trees"  :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"  :  ({"insane", "diseased", "rotten", "twisted"}),
      "plants"  :  ({"dead", "dry"}),
      "canopy"    :  "thick",
      "vines"    :  ({"fuzzy", "tangled"}),
      "branch"    :  "overlapping", 
    ]) );
    SetSmell( ([
      "default"  :  "The scent of the forest is about.",
    ]) );
    SetListen( ([
      "default"  :  "The sounds of life echo between trees.",
    ]) );
    SetExits( ([
      "northeast"  :  ROOMS + "/thicket.c",
      "east"  :  ROOMS + "/forest2.c",
      "southwest"  :  ROOMS + "/oppos.c",
    ]) );
}
