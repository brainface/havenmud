/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../trog.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in a foul smelling burrow");
  SetClimate("underground");
  SetExits( ([
    "west"  : TROG_ROOM "trog06",
    "north" : TROG_ROOM "trog07",
    ]) );
  SetLong(
    "This section of the burrow involves a curve in the tunnel. "
    "Back to the north, the burrow heads back towards the main "
    "tunnels, while to the west the tunnel seems to be, relatively, "
    "more open and well-tended."
    );
  SetItems( ([
    ]) );
  SetInventory( ([
    TROG_NPC "trog2" : 1,
    TROG_NPC "trog3" : 1,
    ]) );
  SetSmell("The burrow has a foul stench that seems to ooze from the walls.");
}