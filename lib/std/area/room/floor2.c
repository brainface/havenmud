#include <lib.h>
#include "../area.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("up the chimney");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetLong("This room is an attic of sorts at the top of the chimney.");
  SetInventory( ([
    AREA_OBJ "chimney" : 1,
  ]) );
 }
