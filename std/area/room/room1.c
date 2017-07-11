/* a room to demonstrate the use of keys and doors
 * Dylanthalus@Haven
 */

#include "../area.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("outside a small cabin");
  SetClimate("temperate");
  SetExits( ([
    "west" : "basic",
    "south" : "wharf",
    ]) );
  SetLong("There is a large cabin here which seems to cozily sit in "
          "the middle of this valley. Back to the west is the "
          "central plain of the valley. There is a large brown tent here.");
  SetItems( ([
  "cabin" : "This is a large and cozy cabin.  It appears to have a door.",
  "tent" : "This is a large brown tent, oddly enough.",
    ]) );
  SetItemAdjectives( ([
    "tent" : ({ "large", "brown" }),
    ]) );
  SetInventory( ([
    AREA_OBJ "cabin_key" : 1,
    AREA_OBJ "button" : 1,
  ]) );
  SetEnters( ([
    "cabin" : AREA_ROOM "cabin",
    "tent" : AREA_ROOM "brown",
  ]) );
  SetDoor("cabin", AREA_OBJ + "cabin_door");
 }
