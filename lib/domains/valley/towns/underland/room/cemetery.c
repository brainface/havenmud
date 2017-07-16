/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetExits( ([
    "east" : "road08",
    ]) );
  SetShort("a peaceful cemetery glade");
  SetLong(
    "A small grassy area opens here, with a few benches set nearby to a serious of trees "
    "that provide a nice shade. A path opens to the east back into the town. The ground itself "
    "is a well-tended lawn of pleasant green. Like many things in Underland, the local cemetery "
    "has a pleasant, friendly personality. A light breeze rolls over the gentle grassland."
    );
  SetSmell("The breeze keeps the air fresh and pleasant.");
  SetListen("The cemetery is a place of quiet contemplation.");
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}
