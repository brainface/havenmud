#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Emotional Room");
  SetLong("This is the place to post emote requests. Ain't it just peachy?");
  SetListen("default", "The silence in here is overpowering.");
  SetInventory( ([ "/secure/obj/emotes_board" : 1 ]) );
  SetExits( ([
     "north" : "/domains/staff/staffroom",
     "east" : "builder",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}

