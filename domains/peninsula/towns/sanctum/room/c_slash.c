#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Sanctum Colosseum");
  SetExits( ([
    "east" : ROME_ROOM "colosseum",
    "south" : ROME_ROOM "c_pierce",
    "southeast" : ROME_ROOM "c_melee",
    ]) );
  SetInventory( ([
    ROME_NPC "t_slash" : 1,
    ]) );
  SetLong("Here in the northwest corner of the Colosseum, "
          "slashing weapons are the rule. Swords of all "
          "varieties litter the ground in various states "
          "of decay, none of them usable anymore. To the "
          "east lies the entrance to the Colosseum floor, "
          "where the Colosseum offers free training weapons. "
          "Off in other directions, other trainers ply their "
          "various trades.");
  SetListen( ([
     "default" : "The sounds of gladiators training fills the air.",
  ]) );
  SetSmell( ([
     "default" : "The smells of sweat and stale blood hang in the air.",
  ]) );
}
