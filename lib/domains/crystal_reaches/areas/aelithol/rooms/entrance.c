#include <domains.h>
#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;

    static void create() {
    room::create();
    SetClimate("temperate");
    SetDomain("Crystal Reaches");
    SetShort("the beginnings of a path");
    SetLong(
      "A northwest path can faintly be discerned among the "
      "many trees. It curves around trees and is nothing more "
      "than a faint apparition, for it is now disappearing. "
      "The trees surrounding the path appear to have once "
      "possessed great strength, but now they have lost their "
      "bark and many have nearly died. However, certain "
      "mangled trees are prospering, but it is obvious that "
      "their cores are black and diseased.");
    SetItems( ([
      ({"trail", "path"})  :  (: GetLong :),
      ({"tree" , "trees", "branch", "branches", "forest"}) :
      "The trees are still extremely large and many have reached "
      "gargantuan proportions, but it is clear that they are now "
      "diseased and many are dying.",
      "bark"  :
      "The bark of many trees is missing exposing green or brown "
      "wood that is anything but healthy.  The bark that still remains "
      "on some of the trees has grown thick and black in an attempt "
      "to fight some unseen enemy.",
      "wood"  :
      "Missing bark exposes the rotten wood of the trees.",
    ]) );
    SetItemAdjectives( ([
      "trail"    :  ({"winding", "curving", "dark"}),
      "wood"    :  ({"brown", "green", "unhealthy", "rotten"}),
      "bark"     :  ({"thick", "black", "dieing"}),
      "tree"    :  ({"large", "gargantuan", "big", "diseased", "great"}),
    ]) );
    SetSmell( ([
      "default"  :  "The air smells of burnt underbrush.",
    ]) );
    SetListen( ([
      "default"  :  "The area is silent.",
    ]) );
    SetExits( ([
      "northwest"  :  ROOMS + "/entrance2.c",
      "south" : CRYSTAL_REACHES_VIRTUAL + "glimmerdinroad/-8,22",
    ]) );
}
