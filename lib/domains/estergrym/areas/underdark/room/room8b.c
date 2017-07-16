#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a curving tunnel");
  SetLong("A narrow, sloping, curved tunnel. It slopes up to the east, "
          "and curves around sloping down to the northwest. An evil "
          "darkness flows up out of the depths of the caves.");
  SetExits( ([
          "northwest" : U_ROOM + "room11b",
          "east" : U_ROOM + "room9b"]) );
  SetItems( ([
          "tunnel" : "A narow curving tunnel. It runs from northwest to east."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
          U_NPC + "dwarf_soldier" : 2 ]) );
  }
