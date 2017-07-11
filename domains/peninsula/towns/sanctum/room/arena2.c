#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("the floor of the Arena");
  SetExits( ([
    "north" : ROME_ROOM "arena1",
    ]) );
  SetLong(
    "The floor of the arena is a sandy dirt, which makes for excellent "
    "footing and also hides blood very well. Stone walls rise on all sides, "
    "preventing any unusual tactics. Only one way exists to leave the arena "
    "without shame: Victory."
    );
  SetSmell("The air is dusty and smells of blood and sweat.");
  
}
  