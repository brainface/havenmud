#include <lib.h>
#include <std.h>
#include "../grymxoria.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(20);
  SetShort("a cemetery");
  SetLong(
    "The Grymxoria cemetery. There are many crypts and tombs "
    "of the fallen Nosferatu here, built out of the stone of the "
    "mountains rather than dug into the ground."
  );
  SetItems( ([
    ({ "tomb", "tombs" }) : "These are the tombs used by the Nosferatu. "
    "There are large communal tombs, as well as small private tombs. "
    "no graves can be seen, as the rock is to hard."
  ]) );
  SetListen( ([
    "default" : "The cemetery has the stillness of death."
  ]) );
  SetSmell( ([
    "default" : "A smell of embalming herbs pervades the air."
  ]) );
  SetExits( ([
    "out" : G_ROOM + "road10"
  ]) );
  SetInventory( ([
    STD_OBJ "reztotem" : 1,
  ]) );
}

