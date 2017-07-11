#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow curved tunnel");
  SetLong("A narrow, curved, sloping tunnel. It slopes up to the "
          "southeast and curves around sloping down to the north. "
          "An evil darkness flows up out of the depths of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room13b",
          "southeast" : U_ROOM + "room8b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from north to "
          "southeast."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
