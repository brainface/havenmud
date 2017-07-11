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
    "west"  : TROG_ROOM "trog03",
    "south" : TROG_ROOM "trog08",
    ]) );
  SetLong(
    "The burrow curves from the west to the south here, opening slightly "
    "as it curves south. To the west the burrow opens as it nears the "
    "main tunnels, while to the south the tunnel appears slightly better "
    "tended."
    );
  SetItems( ([
    ]) );
  SetInventory( ([
    TROG_NPC "trog2" : 1,
    ]) );
  SetSmell("The burrow has a foul stench that seems to ooze from the walls.");
}