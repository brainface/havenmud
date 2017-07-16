#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;

    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("a clearing");
    SetDomain("Crystal Reaches");
    SetLong(
      "Tall brown grass grows in a this small clearing, "
      "allowing the sky to be clearly visible. Trees densly surround the "
      "clearing and branch out over it with their long, diseased "
      "branches. A dark portal can clearly be seen in the side of the "
      "barrier. Its edges are jagged, crude surfaces which seem to have "
      "been broken. Vines and roots hang out over the portal in a vain "
      "attempt to grow into the very hillside.");
    SetItems( ([
      "clearing"  :  (: GetLong :),
      ({"barrier", "slope", "hillside"}) :
      "The barrier is a wall of earth.  The slope to the top is "
      "incredibly high.  Vegetation covers the barrier in immense "
      "thickness preventing any passage.",
      ({"portal", "entrance"})  :
      "The portal is a dark entrance into the hillside.  The edges "
      "have pieces of broken stone on them which indicate that it "
      "was probably shattered.  Vines and roots hang out over it from "
      "the nearby vegetation, perhaps in an attempt to cover it.",
      ({"tree", "trees", "branches", "branch", "forest"})  :
      "Tall, twisted trees grow all through the barrier and in the "
      "ajoining forest.  Their diseased appearances speak of some "
      "unseen enemy assaulting them.",
      ({"edges", "surface", "edge", "surfaces"})  :
      "The jagged stone edges of the portal "
      "hint at the violent destruction of the door.",
      ({"grass", "grasses"})  :
      "Tall brown grasses fill the clearing and wave gently in the "
      "breeze.",
      ({"vine", "vines"})  :
      "The vines range in color from the green to the black and brown "
      "hues.  They entangle the entire barrier forming a wall of "
      "vegetation.",
      ({"root", "roots"})  :
      "Roots from trees and plants hang over the entrance of the portal.",
      ({"vegetation", "plants"})  :
      "Tall, twisted trees cover the barrier.  Their bark is dark black "
      "and their branches curl and twist in a chaotic fashion.  Vines "
      "have entangled themselves badly through the many trees and "
      "undergrowth.",
    ]) );
    SetItemAdjectives( ([
      "barrier"    :  ({"great", "impenetrable", "dense"}),
      "clearing"  :  ({"small", "grassy"}),
      "portal"    :  ({"dark", "broken", "shattered", "hillside"}),
      "tree"    :  ({"black", "diseased", "dying", "tall", "twisted",
        "thick", "dense", "entangled", "dark"}),
      "vine"    :  ({"green", "brown", "black", "entangled"}),
      "edges"    :  ({"jagged", "broken", "rough", "shattered"}),
      "grasses"    :  ({"tall", "brown", "waving"}),
      "vegetation"  :  ({"vile", "twisted", "entangled", "impenetrable"}),
      "root"  :  "hanging",
    ]) );
    SetSmell( ([
      "default"  :  "The smell of upturned earth fills the air.",
    ]) );
    SetListen( ([
      "default"  :  "The area is silent.",
    ]) );
    SetEnters( ([ ( "portal" ) :
      ROOMS + "/tunbeg",
    ]) );
    SetExits( ([
      "southeast"  :  ROOMS + "/entrance2.c",
    ]) );
}
