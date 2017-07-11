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
    "west"  : TROG_ROOM "trog01",
    "east"  : TROG_ROOM "trog07",
    ]) );
  SetLong(
    "The burrow continues from west to east here, opening slightly "
    "as it heads east. To the west the burrow opens as it nears the "
    "main tunnels, while to the east the tunnel appears slightly better "
    "tended."
    );
  SetItems( ([
    ]) );
  SetInventory( ([
    TROG_NPC "trog2" : 1,
    ]) );
  SetSmell("The burrow has a foul stench that seems to ooze from the walls.");
}