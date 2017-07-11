//Artanis was here

#include <lib.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("The Sage Room");
  SetLong(
     "This is where the Sages come to discuss ideas. "
  );
  SetListen( ([
     "default" : "The silence in here is overpowering."
  ]) );
  SetInventory( ([
    "/secure/obj/sage_board" : 1,
  ]) );
  SetExits( ([
     "up" : "/domains/staff/staffroom",
     "down" : "admin",
  ]) );
}

int CanReceive(object ob) {
  if (!sagep(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
