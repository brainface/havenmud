#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the building");
  SetExits( ([
    "out" : AREA_ROOM "path02",
    ]) );
  SetInventory( ([
    AREA_NPC "skel01" : 2,
    ]) );
  SetLong("The building seems to be an old, forgotten shrine to some "
          "god. Outside, the grove sits as a quiet guardian for the "
          "forgotten gods of this temple. The stone walls are lined "
          "with images of death and destruction, and the faintly reddish "
          "coloring used to define the tragic battles does not look like "
          "paint.");
  SetSmell( ([
    "default" : "The smell of dust mixes with the unmistakable smell of blood.",
    ]) );
  SetListen( ([
    "default" : "The shrine is utterly silent.",
    ]) );
  SetClimate("indoors");
  SetWarmth(5);
}
