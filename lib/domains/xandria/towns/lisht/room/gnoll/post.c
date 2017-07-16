#include <lib.h>
#include "../../lisht.h"
inherit LIB_POST_OFFICE;

static void create() {
  ::create();
  SetShort("inside the marble office");
  SetExits( ([
    "out" : LISHT_ROOM "gnoll/pr3",
    ]) );
  SetTown("Lisht");
  SetLong("This is a marble building used by the local inhabitants "
          "to communicate with other towns. The walls of the "
          "place are well maintained and the building has a stately "
          "and admirable quality to it.");
  SetListen( ([
    "default" : "Silence hangs in the air like a weight.",
    ]) );
  SetClimate("indoors");
}

