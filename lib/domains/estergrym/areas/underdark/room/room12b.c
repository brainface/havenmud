#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow curved tunnel");
  SetLong("A narrow, curved, sloping tunnel. It slopes up to the south "
          "and curves around sloping down to the northwest. An evil " 
          "darkness flows up out of the depths of the caves.");
  SetExits( ([
          "northwest" : U_ROOM + "room14b",
          "south" : U_ROOM + "room10b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from northwest to south."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
          U_NPC + "dwarf_soldier" : 2 ]) );
  }
