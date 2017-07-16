#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "west" : "level1hub",
    ]) );
  SetShort("a peaceful cemetery glade");
  SetLong(
    "A large cavernous tomb with body holes in the walls"
    );
  SetSmell("The dust is thick with the smell of the long dead.");
  SetListen("The cemetery is a place of quiet contemplation.");
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
