#include <lib.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("in Mike's broken room");
  SetExits( ([
    "out" : "/domains/southern_coast/towns/haven/room/wharf",
    ]) );
}
