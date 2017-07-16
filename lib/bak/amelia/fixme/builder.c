// Artanis was here 1/18/2003
#include <lib.h>
#include <domains.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(35);
  SetShort("Magical Discussion Room - PLAYER BOARD");
  SetClimate("indoors");
  SetLong(
     "This is where anything magic related is discussed. "
  );
  SetListen("default","The silence looms like an unwelcome intruder.");
  SetInventory( ([
     SOUTHERN_COAST_TOWNS "haven/obj/spell_board" : 1,
  ]) );
  SetExits( ([
     "north" : "humor",
  ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
