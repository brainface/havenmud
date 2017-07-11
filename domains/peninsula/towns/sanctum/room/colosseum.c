#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Colosseum of Sanctum");
  SetExits( ([
    "out" : ROME_ROOM "rd11",
    "east" : ROME_ROOM "c_pole",
    "west" : ROME_ROOM "c_slash",
    "south" : ROME_ROOM "c_melee",
    "southwest" : ROME_ROOM "c_pierce",
    "southeast" : ROME_ROOM "c_hack",
    ]) );
  SetInventory( ([
    ROME_NPC "xoran" : 1,
    ROME_NPC "marcus" : 1,
    ]) );
  SetListen( ([
    "default" : "The sounds of gladiators training fills the air.",
    ]) );
  SetSmell( ([
    "default" : "The smells of sweat and stale blood hang in the air.",
    ]) );
  SetLong("The floor of the Colosseum is designed for training gladiators "
          "and soldiers alike. Masters of various weapons take their time "
          "showing new recruits the arts of martial warfare. Around the "
          "floor of the arena, men train with everything from spears to "
          "swords to axes. To the east, men are training with spears. "
          "To the south, unarmed fighting seems to be a highly sought bit "
          "of knowledge. To the west are swordsmasters, and in the far "
          "corners of the Colosseum are axe and rapier masters.");
}
