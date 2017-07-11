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
    "east"     : TROG_ROOM "trog06",
    ]) );
  SetLong(
    "This section of the burrow appears to be the center of the hive. "
    "A large raised section in the middle of the area is obviously "
    "the home of the ruler of this place. The tunnel heads back to "
    "the east, leading to a slightly less foul section of the burrow."
    );
  SetItems( ([
    ]) );
  SetInventory( ([
    TROG_NPC "trog3" : 1,
    TROG_NPC "trog_queen" : 1,
    ]) );
  SetSmell("The burrow has a foul stench that seems to ooze from the walls.");
}