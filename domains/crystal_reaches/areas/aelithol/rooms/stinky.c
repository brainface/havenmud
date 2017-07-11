#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a small clearing");
    SetDomain("Crystal Reaches");
    SetLong(
      "Tall, brown grass grows in tufts all through the "
      "clearing. A noxious liquid has pooled in the slightly "
      "sunken regions between tufts. The grass has turned "
      "yellow and seems to suffer with the presence of the "
      "substance. Trees densely surround the clearing and their "
      "branches reach out over the grass."
    );
    SetItems( ([
      ({"tree", "trees"})  :  
      "Many of the trees are sick and some are dead.  They are being "
      "affected by some dark power which is at work on the entire "
      "forest.  The trees surrounding the clearing have branches "
      "which reach out over the grass.",
      ({"vegetation", "forest", "woods", "wood", "undergrowth"})  :
       "Vines and lichens hang from trees which become more densely "
       "concentrated farther to the east.  Much of the undergrowth is "
       "composed of vines and other unpleasant forms of vegetation.",
       "clearing"  :  (: GetLong :),
       ({"vine", "vines"})  :
       "Fuzzy vines loop around trees and hang from their branches. ",
       ({"grass", "grasses", "tufts", "tuft"})  :
       "The tall, brown grass grows in tufts throughout the clearing.",
       ({"branch", "branches"})  :
       "The barren branches hang out over the clearing.",
       ({"liquid", "substance", "pool", "pools"})  :
       "The liquid is a translucent substance which emits "
       "the foul stench of a strong acid. It appears to have a negative "
       "effect on the surrounding vegetation.",
    ]) );
 
    SetItemAdjectives( ([
      "tree"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "vegetation"    :  ({"insane", "diseased", "rotten", "twisted"}),
      "clearing"  : "small",
      "vines"    :  ({"fuzzy", "tangled"}),
      "grass"    :  ({"tall", "brown"}),
      "branch"    :  "overlapping", 
      "liquid"  :  ({"caustic", "acrid", "clear", "foul", "translucent"}),
    ]) );
    SetSmell( ([
      "default"  :  "A foul, acrid stench hangs in the air.",
    ]) );
    SetListen( ([
      "default"  :  "The sounds of the forest are all about.",
    ]) );
    SetInventory(([
       NPCS + "/beast.c" : 5 
    ]));
    SetExits( ([
      "north"  :  ROOMS + "/evendeeper.c",
      "west"   :   ROOMS + "/nearstinky.c",
    ]) );
}
