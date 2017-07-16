/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../thra.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "southeast" : THRA_ROOM "center",
    ]) );
  SetShort("the northwest platform of Thra");
  SetLong(
    "This platform seems more involved with the plants than most of the others. Vines "
    "extend over the platform floor and onto the platform itself. "
    );
  SetInventory( ([
    THRA_NPC "druid" : 1,
    ]) );
}