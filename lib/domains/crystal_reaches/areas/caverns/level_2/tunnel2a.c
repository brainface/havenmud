/*  A Tunnel leading from the Cavern to the Chasm  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(0);
  SetShort("a tunnel");

  SetLong("This is a very indistinguishable tunnel.  The walls have long "
          "since been worn smooth.  The ground is flat from years of foot "
          "use, as well as erosion.  The ceiling has the most variation as "
          "from place to place it will rise and fall.  There is also an "
          "occasional crack, but even that isn't of much to note.");

  SetSmell( ([
    "default"  :  "On the breeze the fresh air weighs heavy with the faint "
                  "smell of water.",
  ]) );

  SetListen( ([
    "default"  :  "A leathery flapping sound comes from the north.",
  ]) );

  SetExits( ([
    "north"      :  ROOMLV2 + "/cave2d",
    "southeast"  :  ROOMLV2 + "/tunnel2b",
  ]) );
  SetObviousExits("north, southeast");

  SetItems( ([
    ({ "tunnel", "indistinguishable tunnel" })  :  (: GetLong :),
    ({ "walls", "wall" })  :
       "The walls have long since been worn smooth by some presence long "
       "gone, perhaps some people carved and smoothed the tunnel or maybe "
       "even flowing water could have smoothed these walls.",
    ({ "ground" })  :
       "The ground is very smooth and flat.  Probably from years of foot use "
       "or perhaps water erosion.",
    ({ "ceiling", "crack", "cracks", "occasional crack" })  :
       "The ceiling has the most feature to it, as it rises and dips along "
       "the length of the tunnel.  Ocasionally you will spot a few cracks, "
       "but even they are much out of the ordinary.",
  ]) );
}
