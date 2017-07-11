/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../thra.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "down" : THRA_ROOM "center",
    ]) );
  SetShort("within a quiet contemplation glade");
  SetLong(
    "This quiet glade is home to the Shrine of Contemplation, a religious "
    "artifact dedicated to the memory of all the fallen gelflings. Here is "
    "where the spirits of those gelflings that fall into death come before "
    "their final journey into the planes."
    );
  SetItems( ([
    "shrine" : "The Shrine of Contemplation is a large crystal, dark in color, "
               "which gives off a slightly warm feeling of peace and joy.",
    ]) );
  SetItemAdjectives( ([
    "shrine" : ({ "contemplation" }),
    ]) );
  SetInventory( ([
    THRA_NPC "healer" : 1,
    ]) );
  SetListen("It is quiet here, but not unnaturally so.");
}