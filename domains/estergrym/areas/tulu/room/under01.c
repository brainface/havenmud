/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../tulu.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("underground");
  SetShort("under the altar");
  SetLong(
    "The stairway leads down into the depths of the hill. The stairway reaches a level point "
    "here and a large tunnel heads to the north. The walls of the tunnel seem smooth and "
    "well crafted."
    );
  SetExits( ([
    "up" : TULU_ROOM "hill03",
    "north" : TULU_VIRTUAL "0,0",
    ]) );
  SetInventory( ([
    TULU_NPC "cultist_fighter" : 5,
    ]) );
}
