#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloped tunnel");
  SetLong("A narrow, sloping tunnel. It slopes up to the south "
          "and down to the north. An evil darkness flows up out "
          "of the depths of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room12b",
          "south" : U_ROOM + "room9b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from north to south."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
