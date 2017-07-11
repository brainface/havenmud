/*  A tunnel leading down. */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;
int PreExit(string);

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("a section of the tunnel");
  SetObviousExits("down, west");
  SetAmbientLight(18);
  SetLong("The tunnel leads here to a small hole leading down further "
          "into the ground. Back to the west the tunnel opens into up "
          "the sky, making it possible to leave the tunnel system. "
          );
  SetListen( ([
       "default" : "The chattering of the life above ground is a faint "
                   "and distant echo.",
     ]) );
  SetSmell( ([
       "default" : "An earthy aroma is all around.",
     ]) );
  SetExits( ([
      "west" : STRYKE_LAIR + "1_a",
     ]) );
  AddExit("down", STRYKE_LAIR + "2_a", (: PreExit :) );
 }

int PreExit(string dir) {
   return 1;
   }
