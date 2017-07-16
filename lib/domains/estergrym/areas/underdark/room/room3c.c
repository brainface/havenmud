#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow sloping tunnel");
  SetLong("A narrow, sloping tunnel. It slopes sharply up to the "
          "south and down to the north. "
          "An evil darkness flows up out of the depths of the caves.");
  SetExits( ([
          "north" : U_ROOM + "room7c",
          "up" : U_ROOM + "room19b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from north to "
          "south."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetTouch( ([
          "default" : "The darkness is so thick, it is almost touchable."]) );
  SetInventory( ([
          U_NPC + "dwarf_lieutenant" : 1,
         ]) );
 }
