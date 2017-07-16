/*  part of the tunnel */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a small campsite");
  SetLong("This part of the cave seems to lead off to the southeast, "
          "the northwest, and the southwest.  The cave gets deeper and "
          "goes further into the earth to the east, while the west seems "
          "to be closer to the surface.  The remains of a campsite litter "
          "the ground.");
  SetItems( ([
     ({ "camp", "campsite" }) : "The campsite has all but been cleaned up "
                                "and very little is left.",
        ]) );
  SetInventory( ([
      STRYKE_NPC + "explorer" : 3,
       STRYKE_OBJ + "fire" : 1,
    ]) );
  SetObviousExits("southeast, southwest, northwest");
  SetExits( ([
      "southeast" : STRYKE_LAIR + "2_g",
      "southwest" : STRYKE_LAIR + "2_e",
      "northwest" : STRYKE_LAIR + "2_a",
  ]) );
  SetSmell( ([
     "default" : "The smell of the smoke mutes the earthy smell of the tunnel.",
      ]) );
  SetListen( ([
      "default" : "The campfire's crackle is all that can be heard.",
      ]) );
  }

