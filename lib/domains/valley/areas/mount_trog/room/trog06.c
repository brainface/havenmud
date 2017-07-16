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
    "west" : TROG_ROOM "trog05",
    "east" : TROG_ROOM "trog08",
    ]) );
  SetLong(
    "Directly to the west the burrow opens into a fairly large center. "
    "To the east the tunnel begins a curve that leads it away from the "
    "spiral center of the hive."
    );
  SetItems( ([
    ]) );
  SetInventory( ([
    TROG_NPC "trog3" : 1,
    TROG_NPC "trog2" : 2,
    ]) );
  SetSmell("The burrow has a foul stench that seems to ooze from the walls.");
}