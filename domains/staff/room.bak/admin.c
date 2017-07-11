#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Admin Room");
  SetLong("This is the place to post notes.  Nice, yes?");
  SetListen("default", "The silence in here is overpowering.");
  SetInventory( ([ "/secure/obj/admin_board" : 1 ]) );
  SetExits( ([
    "up" : "sageroom",
    ]) );
}

int CanReceive(object ob) {
  if (!adminp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
