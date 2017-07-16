#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "west" : ROME_ROOM "colosseum",
    "south" : ROME_ROOM "c_hack",
    "southwest" : ROME_ROOM "c_melee",
    ]) );
  SetInventory( ([
    ROME_NPC "t_pole" : 1,
    ]) );
  SetLong("Lying broken on the ground are staves of all shapes "
          "and sizes. Here, two-handed staves are trained with "
          "all the skill and style that requires. To the west is "
          "the entrance to the Colosseum, while in all other "
          "directions training is taking place.");
  SetListen( ([
     "default" : "The sounds of gladiators training fills the air.",
  ]) );
  SetSmell( ([
     "default" : "The smells of sweat and stale blood hang in the air. ",
  ]) );
}
