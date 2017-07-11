/*  A Tunnel leading from the Cavern to the Chasm  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a tunnel");

  SetLong("This is a very indistinguishable tunnel.  The walls and ground of "
          "the tunnel have long since been worn smooth by the forces of "
          "nature.  The ceiling deviates slightly from this featureless norm "
          "by rising and falling.  Yet the ceiling too is smooth and the only "
          "feature it has is are the few cracks that line the ceiling.");

  SetSmell( ([
    "default"  :  "On the breeze the fresh air weighs heavy with the faint "
                  "smell of water.",
  ]) );

  SetListen( ([
    "default"  :  "A faint rumbling is noticeable here.",
  ]) );

  SetExits( ([
    "northwest"  :  ROOMLV2 + "/tunnel2a",
    "east"       :  ROOMLV2 + "/tunnel2c",
  ]) );
  SetObviousExits("northwest, east");

  SetItems( ([
    ({ "tunnel", "indistinguishable tunnel" })  :  (: GetLong :),
    ({ "walls", "wall" })  :
       "The walls have long since been worn smooth by some presence long "
       "gone, perhaps some people carved and smoothed the tunnel or maybe "
       "even the flow of water could have smoothed these walls.",
    ({ "ground" })  :
       "The ground is very smooth and flat.  Probably from years of foot use "
       "or perhaps water erosion.",
    ({ "ceiling", "crack", "cracks" })  :
       "The ceiling has the most feature to it, as it rises and dips along "
       "the length of the tunnel.  Ocasionally you will spot a few cracks, "
       "but they are much out of the ordinary.",
  ]) );
}
