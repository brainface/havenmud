#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "east" : ROME_ROOM "c_melee",
    "northeast" : ROME_ROOM "colosseum",
    "north" : ROME_ROOM "c_slash",
    ]) );
  SetInventory( ([
    ROME_NPC "t_pierce" : 1,
    ]) );
  SetLong("Here in the southwest corner of the Sanctum Colosseum, "
          "speed and quickness reign. The piercing variety of sword, "
          "such as the rapier, seems to be the weapon of choice here. "
          "In all other directions, training seems to be occuring on a "
          "continuous basis. To the northeast is the entrance to the "
          "Colosseum.");
  SetListen( ([
     "default" : "The sounds of gladiators training fills the air. ",
  ]) );
  SetSmell( ([
     "default" : "The smells of sweat and stale blood hang in the air. ",
  ]) );
}
