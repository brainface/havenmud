/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../sheep.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a short-cropped field");
  SetExits( ([
    "west" : SHEEP_ROOM "field3",
    "north": SHEEP_ROOM "field5",
    ]) );
  SetLong(
    "The grass here is short-cropped, as if it were well maintained by the feasting "
    "of large animals. "
    "Further east and north across the field a large manor house can be seen. The field spreads "
    "out to the north and west from here."
    );
  SetSmell("The smell of animal dung pollutes the air.");
  SetInventory( ([
    SHEEP_NPC "sheep" : random(3),
    SHEEP_NPC "cow"   : random(3),
    ]) );
}