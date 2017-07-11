#include <lib.h>
#include "path.h"

inherit LIB_ROOM;
static void create () {
    room::create();
    SetShort("a muddy ditch");
    SetLong("The road slopes downward a bit into a muddy ditch.  Puddles "
          "are scattered erratically about, with huge footprints indented "
          "into the mud.  A hastily erected tent stands to the west.");
          SetItems( ([
          ({ "puddles" }) :
          "The puddles were formed by heavy rainfall onto the already soaked "
          "ground.",
          ({ "soaked ground", "ground" }) :
           "The ground is saturated with water from repeated rainfall.",
          ({ "huge footprints", "footprints" }) :
          "These footprints look like they were created by creatures much "
          "larger than humans.",
          ({ "road" }) :
          "The road slopes down into the mud.",
          ({ "ditch" }) :
          "The ditch was obviously created by some heavy rainfall, and the "
          "mud is still wet.",
          ({ "hastily erected tent", "tent" }) :
          "This tent looks like it was set up in a hurry, but it looks large "
          "enough to be comfortable.",
          ({ "mud" }) :
          "The mud is sticky and wet, and sloshes around whenever you step "
          "in it.",
           ]) );
    SetExits( ([
          "east" : BEORN_ROOM + "field1.c",
           ]) );
    SetEnters( ([
          "tent" : BEORN_ROOM + "tent1.c",
           ]) );
    SetObviousExits("east");
    SetInventory( ([
            BEORN_NPC + "osoldier.c" : 1,
            ]) );
}
