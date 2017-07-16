//Artanis was here

#include <lib.h>

inherit LIB_ROOM;

static void create() {
  room::create();
  SetAmbientLight(35);
  SetClimate("indoors");
  SetShort("The upper layer of Heaven");
  SetLong(
     "Just a place so where more rooms can be attached. "
  );
  SetListen( ([
     "default" : "The silence in here is overpowering. ",
  ]) );
  SetInventory( ([
  ]) );
  SetExits( ([
     "north" : "archroom",
     "down" : "/domains/staff/staffroom",
  ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
