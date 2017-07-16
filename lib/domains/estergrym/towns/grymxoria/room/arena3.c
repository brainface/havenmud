#include <lib.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Grymxoria");
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("the Grymxoria fighter's lounge");
  SetLong(
    "A large dimly lit room. At one end is a large bar. "
    "Scattered across the room are round wooden tables and "
    "chairs. Many stained by spills or other, more violent, "
    "activities. On one wall is a large bulletin board "
    "where the fighters may post their opinions."
  );
  SetExits( ([
    "west" : G_ROOM + "arena2"
  ]) );
  SetInventory( ([
  ]) );
}

