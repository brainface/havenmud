/*  Level #2 - Chasm - Section #4  */

#include <lib.h>
#include "../caves.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(0);
  SetShort("an enormously large chasm");

  SetLong("This is where the ledge along the chasm stops.  To the southeast "
          "the ledge has collapsed and has been swallowed up by the seemingly "
          "bottomless chasm.  Something on the walls seems to have caught the "
          "light.  The ledge follows the chasm to the north.");

  SetSmell( ([
    "default"  :  "The air is surprisingly damp here.",
  ]) );

  SetListen( ([
    "default"  :  "You seem to hear grunting and soft thuds above the roaring "
                  "noise to the north.",
  ]) );

  SetExits( ([
    "north"  :  ROOMLV2 + "/chasm2c",
  ]) );
  SetObviousExits("north");

  SetSearch( ([
    ({ "walls", "wall" })  :  "The walls around you have already been cleared "
       "of anything that is valuable.",
  ]) );

  SetItems( ([
    ({ "chasm", "large chasm", "enormously large chasm" })  :  (: GetLong :),
    ({ "ledge" })  :
       "The ledge continues on to the north following the chasm.  While the "
       "ledge to the southeast has collapsed into the seemingly bottomless "
       "chasm.",
    ({ "walls", "wall" })  :
       "The walls around you sparkle from the various gems and veins of metal "
       "embedded in them.",
    ({ "bottomless chasm" })  :
       "The chasm goes down... and down... and down... until finally darkness "
       "steals the light that falls into it.",
  ]) );
}
