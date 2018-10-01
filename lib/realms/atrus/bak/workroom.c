#include <lib.h>
#include <std.h>
#include <dirs.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a workroom");
  SetLong("This is your basic workroom. There is not much to see "
          "here, but if you were interested, you could go north "
          "to get to the staff room of the Immortals. Or you could "
          "enter the cave to see the current project.");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetItems( ([
       ({ "cave" }) : "Yes, it's a cave.",
       ]) );
  SetEnters( ([
     "cave" : "/realms/tassadar/areas/prasanna/room/caventr",
       ]) );
  SetExits( ([
    "south" : "/realms/tassadar/misc/mine1",
     "north" : DIR_STANDARD_DOMAIN "/staffroom",
     "east"  : STD_AREA "room/basic",
      ]) );
  SetInventory( ([
     "/realms/tassadar/ram" : 1
  ]) );
  }
