#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
  SetAmbientLight(35);
    SetClimate("indoors");
    SetShort("The OOC Board -- PLAYER ACCESSABLE");
  SetLong("This is the place to post OOC Stuff.  Nice, yes?");
  SetListen( ([
     "default" : "The silence in here is overpowering.",
  ]) );
  SetInventory( ([ "/secure/obj/ooc_board" : 1 ]) );
  SetExits( ([
    "south" : "../staffroom",
    "east"  : "ideas",
    ]) );
}

int CanReceive(object ob) {
  if (!creatorp(ob) && userp(ob)) return 0;
  return ::CanReceive(ob);
}
