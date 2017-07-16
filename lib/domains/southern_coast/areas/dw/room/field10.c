/*  Extension of the Haven Town Swampland */
#include <lib.h>
#include "../newbie.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("sub-arctic");
  SetShort("near a small stone tomb");
  SetLong("The quiet cemetery path seems to lead here up to another "
          "tomb of some sort. The overgrown grasses freely propogate "
          "right up to the edges of the tomb, but do not seem to "
          "disturb its slumber in any way. Back to the west the "
          "cemetary opens into its main sections.");
  SetListen( ([
    "default" : "The stony silence of death long past rocks the air.",
    ]) );
  SetSmell( ([
    "default" : "The rot of the swampground fills the air with its "
                "stench.",
    ]) );
  SetExits( ([
     "west" : NEWBIE_ROOM + "/field7",
    ]) );
  SetItems( ([
     ({ "tomb" }) : "The tomb seems to be a large stone structure.",
     ({ "grasses", "grass" }) : "The grasses are normal grass, "
                                "but even they seem to avoid the tomb.",
    ]) );
  SetEnters( ([
      ({ "tomb" }) : NEWBIE_ROOM + "/vamp_tomb",
    ]) );
 }
