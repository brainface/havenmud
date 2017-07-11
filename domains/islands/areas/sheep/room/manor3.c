#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside a cabin");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong("This cabin is a soft and warm place to rest from the "
          "elements. The chimney seems to take up a large part of "
          "the room.");
  SetExits( ([
    "out" : "room1",
  ]) );
  SetDoor( "out", AREA_OBJ "cabin_door");
  SetInventory( ([
    AREA_OBJ "chimney" : 1,
    AREA_OBJ "sword" : 1,
    AREA_OBJ "chain" : 1,
    AREA_OBJ "beanbag" : 1,
  ]) );
 }
