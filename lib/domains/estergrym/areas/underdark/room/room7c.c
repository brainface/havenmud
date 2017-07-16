#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow tunnel");
  SetLong("A narrow tunnel. It slopes up to the south and down to the "
          "northwest. An evil darkness flows up out of the depths of the "
          "caves.");
  SetExits( ([
          "northwest" : U_ROOM + "room12c",
          "south" : U_ROOM + "room3c"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from northwest to "
          "south."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetTouch( ([
          "default" : "The darkness is so thick, it is almost touchable."]) );
 }
