#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the entrance to the Arena");
  SetClimate("underground");
  SetAmbientLight(35);
  SetExits( ([
    "north" : ROME_ROOM "c_melee",
    "south" : ROME_ROOM "arena2",
    ]) );
  SetLong(
    "This is the entrance to the Arena of Sanctum. All Arena business is conducted "
    "from here. This large stone tunnel leads directly into the fighting pit. "
    "Various martial scenes are painted on the walls in an effort to lighten the "
    "spirit of those who are about to die."
    );
  SetSmell("A faint coppery smell seems to permanently flaw the tunnel.");
  SetInventory( ([
    ROME_NPC "titus" : 1,
    ]) );
}
  
