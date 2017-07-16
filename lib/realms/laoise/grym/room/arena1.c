#include <lib.h>
inherit LIB_ROOM;
#include "../grymxoria.h"

static void create() {
  room::create();
  SetTown("Grymxoria");
  SetShort("the Grymxoria arena practice room");
  SetLong(
    "A large room with a bare stone floor. Lined up along the walls "
    "are racks of weapons and armor. This is where the gladiators of "
    "Grymxoria practice their fighting techniques. The flagstones of "
    "the floor sport an occasional brownish red spot or splash."
  );
  SetItems( ([
    ({"floor", "spot", "spots", "splash", "splashes", "flagstones", "stone",
    "stone floor"}) : "A bare floor of rectangular gray flagstones. Here "
    "and there is a brownish red splash or spot that is probably blood.",
    ({"rack", "racks", "weapons", "armors", "armors" }) : "Along the "
    "walls of the room are racks of various weapons and armors."
  ]) );
  SetExits( ([
    "east" : G_ROOM + "arena2"
  ]) );
  SetClimate("indoors");
  SetAmbientLight(20);
  SetInventory(  ([
    G_NPC + "thundar" : 1,
    G_NPC + "lothar" : 1,
    G_NPC + "drahcir" : 1
  ])  );
}

