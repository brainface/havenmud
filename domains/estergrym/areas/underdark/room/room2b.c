#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a curving tunnel");
  SetLong("A narrow, sloping, curved tunnel. It slopes up to the north, "
          "and down to the east.  An evil darkness flows up out of the "
          "depths of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room5b",
          "east" : U_ROOM + "room3b"]) );
  SetItems( ([
          "tunnel" : "A narow curving tunnel. It runs from north to east."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetListen( ([
          "default" : "Everything is completely silent."]) );
  }
