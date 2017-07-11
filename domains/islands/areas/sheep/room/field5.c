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
    "west" : SHEEP_ROOM "field1",
    "south": SHEEP_ROOM "field6",
    "north": SHEEP_ROOM "field4",
    "east" : SHEEP_ROOM "manor",
    ]) );
  SetLong(
    "The grass here is short-cropped, as if it were well maintained by the feasting "
    "of large animals. Off in the distance to the west the field heads to a small grassy beach. "
    "Further east a large manor house can be seen. The field spreads "
    "out to the south, north, and west from here."
    );
  SetSmell("The smell of animal dung pollutes the air.");
  SetInventory( ([
    SHEEP_NPC "sheep" : random(3),
    SHEEP_NPC "cow"   : random(3),
    ]) );
}