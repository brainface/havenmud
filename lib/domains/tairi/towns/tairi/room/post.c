#include <lib.h>
#include "../tairi.h"
inherit LIB_POST_OFFICE;

static void create() {
  ::create();
SetAmbientLight(50);
  SetShort("inside the dull building");
  SetExits( ([
    "out" : "path8",
    ]) );
  SetTown("Tairi");
  SetLong("This is a dull building used by the local inhabitants "
          "to communicate with other towns. The old walls of the "
          "place have seen better days, and the rundown look of "
          "despair has claimed this building.");
  SetSmell( ([
    "default" : "The scent of dust fills the air.",
    ]) );
  SetListen( ([
    "default" : "Silence hangs in the air like a weight.",
    ]) );
  SetClimate("indoors");
}

