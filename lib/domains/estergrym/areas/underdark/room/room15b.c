#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a fork in the tunnel");
  SetLong("A fork in the narrow, curved, sloping tunnel. It "
          "slopes up to the north and curves around sloping down to "
          "the southeast and southwest. The tunnel seems to open up "
          "to the north. An evil darkness flows up out of the depths "
          "of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room16b",
          "southeast" : U_ROOM + "room14b",
          "southwest" : U_ROOM + "room13b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from north, forking "
          "into two other tunels heading towards the southeast and "
          "southwest."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
           U_NPC + "dwarf_soldier" : 3 ]) );
  }
