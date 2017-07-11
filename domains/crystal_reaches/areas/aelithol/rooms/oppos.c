#include <lib.h>
#include "../aelithol.h"
inherit LIB_ROOM;
    static void create() {
    room::create();
    SetClimate("temperate");
    SetShort("near a tunnel");
    SetDomain("Crystal Reaches");
    SetLong(
      "The tunnel opens up to a sweet-smelling, "
      "fair land. A portal in the same condition as the one "
      "to the south is here. It was probably destroyed by "
      "the same powerful force. Large fragments of stone "
      "can be seen in the tall grass outside the tunnel portal. "  
      "The edges of the portal are extremely jagged and much "
      "of the hillside stone has been fragmented. Some "
      "great magical force in the hill seems to be fighting "
      "the against the destruction of whatever destroyed the "
      "door."
    );
    SetItems( ([
      ({"land", "landscape"})  :  
      "To the east a ancient forest can be seen and to the west rocky "
      "hills covered in brown grass climb in elevation.",
      "forest"  :
      "An ancient forest is to the northeast.",
      ({"fragments" , "fragment"})  :
      "Pieces of the door which once concealed the tunnel are spread "
      "through grass.  Many of them still have flat surfaces "
      "and were once part of a smooth, stone door.",
      "stone"  :
      "The native stone is dark, but not very damp.",
      ({"edges", "surface", "edge"})  :
      "The edges of the portal have jagged rock edges which "
      "hint at the violent destruction of the door.",
      ({"grass", "grasses"})   :
      "A brown grass grows near the base of the stone.",
      ({"hill", "hillside", "slope", "barrier"})  :
      "The barrier is a wall of earth.  The slope to the top is "
      "incredibly high.  Vegetation covers the barrier in immense "
      "thickness preventing any passage.",
      "tunnel"  :
      "Just beyond the portal, the begginings of a dark tunnel can "
      "barely be seen.",
      "portal"  :
      "The portal is a dark entrance into the hillside.  The edges "
      "have pieces of broken stone still attached that indicate that "
      "the door was probably shattered.  Vines and roots hang out over "
      "it from the nearby vegetation, perhaps in an attempt to cover it.",
      "door"  :
      "At one time the portal was blocked by a stone door, but now the "
      "scattered fragments are all that remain.",
      "vegetation"  :
      "In sharp contrast with the vegetation growing on the opposite "
      "side of the barrier, the plant life on this side is healthy and "
      "full of life.  Vines can still be seen, but they are much less "
      "menacing.",
    ]) );
    SetItemAdjectives( ([
      "land"    :  ({"fair", "magic", "magical", "sweet-smelling"}),
      "stone"    :  ({"dark", "hillside", "native"}),
      "portal"    :  ({"dark", "broken", "shattered", "hillside"}),
      "forest"   :   "ancient",
      "tunnel"   :   "dark",
      "door"   :    "shattered",
      "grass"   :   ({"brown", "waving", "tall"}),
      "landscape"  :  ({"fair", "magic", "magical"}),
      "fragment"    :  ({"scattered", "jagged"}),
      "hill"    :  ({"steep", "impenetrable", "thick", "dense"}),
      "vegetation"    :  ({"thick", "healthy", "nice"}),
    ]) );
    SetSmell( ([
      "default"  :  "Soft smells of the countryside are carried by "
        "the breeze.",
    ]) );
    SetListen( ([
      "default"  :  "Grass faintly rustles in the breeze.",
    ]) );
    SetExits( ([
      "northeast"  :  ROOMS + "/forest.c",
      "south"  :  ROOMS + "/tunnel.c",
      "west"  :  ROOMS + "/hill.c",
    ]) );
}
