#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow curved tunnel");
  SetLong("A narrow, curved, sloping tunnel. It slopes up to the "
          "southeast and curves around sloping down to the northwest. "
          "An evil darkness flows up out of the depths of the caves.");
  SetExits( ([
          "northwest" : U_ROOM + "room15b",
          "southeast" : U_ROOM + "room12b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from northwest to "
          "southeast."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
