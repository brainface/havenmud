//Artanis was here

#include <lib.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("The Arch Room");
  SetLong(
     "This is where the Archs and Assistant Archs come to discuss ideas. "
  );
  SetListen( ([
     "default" : "The silence in here is overpowering."
  ]) );
  SetInventory( ([
    "/secure/obj/arch_board" : 1,
  ]) );
  SetExits( ([
     "down" : "/domains/staff/staffroom",
  ]) );
}

int CanReceive(object ob) {
  if (!archp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
