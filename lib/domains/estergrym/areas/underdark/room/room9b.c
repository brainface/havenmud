#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow tunnel");
  SetLong("A narrow, sloping, tunnel. It slopes down to the north and, "
          "to the west and up to the southwest. The tunnel seems to open "
          "up to the south. An evil darkness flows up out of the depths "
          "of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room10b",
          "south" : U_ROOM + "room7b",
          "west" : U_ROOM + "room8b"]) );
  SetItems( ([
          "tunnel" : "A narow curving tunnel. It runs from the large chamber "
          "in the south to the north."]) );
  SetListen( ([
          "default" : "Everything is completly silent."]) ); 
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  }
