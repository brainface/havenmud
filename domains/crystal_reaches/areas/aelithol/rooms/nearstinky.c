#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("near a clearing");
    SetDomain("Crystal Reaches");
    SetLong(
      "The trees are in lower concentration here. Small tufts "
      "of a brown grass grow can be found, but to the east the "
      "forest opens up to a small clearing. Many of trees here "
      "have become extremely sick. Some appear to be near death, "
      "others are knarled and blackened by some unknown source of "
      "power."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
       "Many of the trees are sick and some are dead.  They are being "
       "affected by some dark power which is at work on the "
       "entire forest.",
       ({"vegetation", "forest", "woods", "wood"})  :
       "Vines and lichens hang from trees which become more densely "
       "concentrated farther to the east.  Much of the undergrowth is "
       "composed of vines and other unpleasant forms of vegetation.",
       ({"branch", "branches"})  :
       "Many of the branches lack leaves and are beggining to twist in a "
       "chaotic fashion.",
       "clearing"   :
       "A clearing can barely be seen to the east.",
       ({"tufts", "grass", "grasses", "tuft"})  :
       "The tall brown grass grows in tufts.  It can be found in greater "
       "concentrations in the nearby clearing.",
      "canopy"  :
      "The branches of the trees overlap forming a thick canopy "
      "above the forest floor.",
    ]) );
    SetItemAdjectives( ([
      "canopy"    :  "thick",
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "tufts"    :  ({"tall", "brown"}),
      "clearing"   :   "eastern",
      "branch"    :  "overlapping", 
    ]) );
    SetSmell( ([
      "default"  :  "A faint acrid scent emanates from the east.",
    ]) );
    SetListen( ([
      "default"  :  "The cries of forest animals echo through the forest.",
    ]) );
    SetExits( ([
      "east" : ROOMS + "/stinky.c",
      "west" : ROOMS + "/forest2.c",
    ]) );
}
