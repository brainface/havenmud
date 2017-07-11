#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "north"     : ROME_ROOM "colosseum",
    "south"     : ROME_ROOM "arena1",
    "east"      : ROME_ROOM "c_hack",
    "west"      : ROME_ROOM "c_pierce",
    "northwest" : ROME_ROOM "c_slash",
    "northeast" : ROME_ROOM "c_pole",
    ]) );
  SetInventory( ([
    ROME_NPC "t_melee" : 1,
    ]) );
  SetLong("Here in the southern part of the Colosseum, unarmed "
          "combat is the rule. Blood seems to stain the dirt, "
          "as if this area were somehow more deadly than other "
          "sections of the Colosseum. To the north lies the "
          "entrance to the Colosseum, while in all other directions "
          "training is taking place. To the south lies the entrance "
          "to the Sanctum Arena.");
  SetListen( ([
     "default" : "The sounds of gladiators training fills the air.",
  ]) );
  SetSmell( ([
     "default" : "The smells of sweat and stale blood hang in the air.",
  ]) );
}
