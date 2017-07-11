#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Idea Summary Room");
  SetLong("This is the place to post Ideas.  Nice, yes?");
  SetListen( ([
     "default" : "The silence in here is overpowering.",
  ]) );
  SetInventory( ([ "/secure/obj/idea_board" : 1 ]) );
  SetExits( ([
    "west" : "ooc",
    "south" : "humor",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
