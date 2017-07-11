#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
   static void create() {
   room::create();
   SetClimate("temperate");
   SetShort("near a barrier");
    SetDomain("Crystal Reaches");
   SetLong(
      "The land rises slightly to meet the a great barrier which "
      "rises from the relatively flat land of the forest at a "
      "amazingly steep angle. Vegetation that grows on the "
      "tremendous slope is not healthy by any definition. Trees are "
      "gnarled and twisted with rotten cores and thick vines twist "
      "wildly through the vegetation. The sheer density of the barrier "
      "makes it entirely impassible."
    );
    SetItems( ([
    ({"land", "landscape"})  :  (: GetLong :),
    ({"barrier", "slope"}) :
      "The barrier is a wall of earth.  The slope to the top is "
      "incredibly high.  Vegetation covers the barrier in immense "
      "thickness preventing any passage.",
    ({"vegetation", "plants", "growth", "undergrowth"})  :
      "Tall, twisted trees cover the barrier.  Their bark is dark black "
      "and their branches curl and twist in a chaotic fashion.  Vines "
      "have entangled themselves badly through the many trees and "
      "undergrowth.",
    ({"tree", "trees", "branches", "branch", "forest"})  :
      "Tall, twisted trees grow all through the barrier and in the "
      "ajoining forest.  Their diseased appearances speak of some "
      "unseen enemy assaulting them.",
    ({"vine", "vines"})  :
      "The vines range in color from the green to the black and brown "
      "hues.  They entangle the entire barrier forming a wall of "
      "vegetation.",
    ]) );
    SetItemAdjectives( ([
      "barrier"    :  ({"great", "impenetrable", "dense"}),
      "vegetation"     :  ({"thick", "dense", "entangled", "dark"}),
      "tree"    :  ({"black", "diseased", "dying", "tall", "twisted"}),
      "vine"    :  ({"green", "brown", "black", "entangled"}),
     ]) );
    SetSmell( ([
      "default"  :  "The scent of ash is strong.",
    ]) );
    SetListen( ([
      "default"  :  "The area is silent.",
    ]) );
    SetExits( ([
      "northwest"  :  ROOMS + "/clearing.c",
      "southeast"  :  ROOMS + "/entrance.c",
    ]) );
}
