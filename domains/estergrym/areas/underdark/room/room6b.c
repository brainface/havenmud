#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a curving tunnel");
  SetLong("A narrow, sloping, curved tunnel. It slopes down to the northeast, "
          "and up to the southwest. The tunnel seems to open up to the "
          "northeast. An evil darkness flows up out of the depths "
          "of the caves.");
  SetExits( ([
          "northeast" : U_ROOM + "room7b",
          "southwest" : U_ROOM + "room5b"]) );
  SetItems( ([
          "tunnel" : "A narow curving tunnel. It runs from the large chamber "
           "in the northeast to the southwest."]) );
  SetListen( ([
          "default" : "Everything is completly silent."]) ); 
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
