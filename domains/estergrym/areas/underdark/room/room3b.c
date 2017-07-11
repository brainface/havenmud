#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a curving tunnel");
  SetLong("A narrow, sloping, curved tunnel. It slopes up to the west, "
          "and down to the northeast. The tunnel seems to open up to the "
          "northeast. An evil darkness flows up out of the depths of the "
          "caves.");
  SetExits( ([
          "northeast" : U_ROOM + "room4b",
          "west" : U_ROOM + "room2b"]) );
  SetItems( ([
          "tunnel" : "A narow curving tunnel. It runs from the large chamber "
          "in the northeast to the west."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetInventory( ([
          U_NPC + "dwarf_soldier" : 1 ]) );
  }
