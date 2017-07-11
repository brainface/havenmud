#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "northwest" : ROME_ROOM "colosseum",
    "west" : ROME_ROOM "c_melee",
    "north" : ROME_ROOM "c_pole",
    ]) );
  SetInventory( ([
    ROME_NPC "t_hack" : 1,
    ]) );
  SetLong("Scattered in the dirt of the southeastern corner of "
          "the Colosseum are various axes and other weapons which "
          "are used in an overhand, hacking manner. To the north"
          "east lies the entrance to the Colosseum, while in all "
          "other directions training is taking place.");
  SetListen( ([
     "default" : "The sounds of gladiators training fills the air. ",
  ]) );
  SetSmell( ([
     "default" : "The smells of sweat and stale blood hang in the air. ",
  ]) );
}
