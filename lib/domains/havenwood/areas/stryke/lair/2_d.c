/*  Part of the tunnel */
#include <lib.h>
#include "../stryke.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetLong("This section of tunnel leads from the north to the southeast, "
          "with little in the way of features or notable terrain. The "
          "few interesting rocks are simply too big to be of any use to "
          "anyone.");
  SetSmell( ([
     "default" : "There is a distinct earthy smell here.",
    ]) );
  SetListen( ([
    "default" : "There is a faint dripping noise echoing through here.",
    ]) );
  SetItems( ([
     ({ "rock", "rock" }) : "The rocks are dull and not very interesting.",
    ]) );
  SetShort("a section of tunnel");
  SetObviousExits("north, southeast");
  SetExits( ([
     "north" : STRYKE_LAIR + "2_a",
    "southeast" : STRYKE_LAIR + "2_e",
   ]) );
  }
