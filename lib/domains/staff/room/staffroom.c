
#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Immortal Lounge");
  SetLong("This is the place for immortals to kick back and relax for a bit.");
  SetListen("default", "The silence in here is overpowering.");
  SetExits( ([
    "west" : "room/start",
    "north" : "room/meeting",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
