#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Immortal Meeting Room");
  SetLong("This is a small room for Immortals to meet and talk about stuff.");
  SetListen( ([
     "default" : "The silence in here is overpowering.",
  ]) );
  SetExits( ([
    "south" : "../staffroom",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
