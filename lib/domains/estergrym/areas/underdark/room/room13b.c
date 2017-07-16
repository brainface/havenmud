#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow curved tunnel");
  SetLong("A narrow, curved, sloping tunnel. It slopes up to the "
          "south and curves around sloping down to the northeast. "
          "An evil darkness flows up out of the depths of the caves.");
  SetExits( ([
          "northeast" : U_ROOM + "room15b",
          "south" : U_ROOM + "room11b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from northeast to "
          "south."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
