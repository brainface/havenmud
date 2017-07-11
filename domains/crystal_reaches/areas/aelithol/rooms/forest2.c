#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("in a forest");
    SetDomain("Crystal Reaches");
    SetLong(
      "The trees here seem to be even more diseased than "
      "the trees on the outer edge of the forest. Many "
      "of the trees are not as large as would be expected "
      "and most have already died or are fast on their way. "
      "Those that have died still stand anchored in the "
      "ground and seem unwilling to surrender even in death."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "The trees are twisted and very diseased.  Some that have already "
      "died still remain anchored in the ground by their dead roots.",
      ({"vegetation", "forest", "woods", "wood"})  :
      "The forest has been made very sick by an unseen force.  "
      "Most of the trees are slowly dying.",
      ({"vine", "vines"})  :
      "Fuzzy vines loop around trees and hang from their branches. ",
      ({"moss", "mosses"})  :
      "Mosses of many colors grow on the forest floor between various "
      "forms of undergrowth.",
      ({"branch", "branches"})  :
      "Many of the branches lack leaves and are beggining to twist in a "
      "chaotic fashion.",
      "canopy"  :
      "The branches of the trees overlap forming a thick canopy "
      "above the forest floor.",
    ]) );

    SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"  :  ({"insane", "diseased", "rotten", "twisted"}),
      "canopy"    :  "thick",
      "vines"    :  ({"fuzzy", "tangled"}),
      "branch"    :  "overlapping", 
    ]) );
    SetSmell( ([
      "default"  :  "The smell of rotting plant matter fills the air.",
    ]) );
    SetListen( ([
      "default"  :  "Forest creatures move about unseen.",
    ]) );
    SetExits( ([
      "west"  :  ROOMS + "/forest.c",
      "north"   :   ROOMS + "/thicket.c", 
      "east"  :  ROOMS + "/nearstinky.c",
    ]) );
}
