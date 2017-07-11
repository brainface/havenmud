#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The Comic Relief Room");
  SetLong("This is the place to post Funny Stuff.  Nice, yes?");
  SetListen( ([
     "default" : "The silence in here is overpowering.",
  ]) );
  SetInventory( ([ "/secure/obj/humour_board" : 1 ]) );
  SetExits( ([
    "west" : "../staffroom",
    "south" : "builder",
    "north" : "ideas",
    "east"    : "portal",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
