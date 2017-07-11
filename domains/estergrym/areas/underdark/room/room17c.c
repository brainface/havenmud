#include <lib.h>
inherit LIB_ROOM;
#include "../underdark.h"

static void create() {
  room::create();
  SetClimate("underground");
  SetAmbientLight(15);
  SetShort("a narrow tunnel");
  SetLong("A narrow tunnel. It slopes up to the "
          "southeast and down to the northwest. The tunnel seems to open up "
          "on to a paved road to the northwest. "
          "An evil darkness flows up out of the depths of the caves. ");
  SetExits( ([
          "northwest" : U_ROOM + "room7c",
          "southeast" : U_ROOM + "room19b"]) );
  SetItems( ([
          "tunnel" : "A narow sloping tunnel. It runs from north to "
          "south.",
          "road" : "It is hard to tell from here, but there seems to be a paved "
          "road starting in the tunnel to the northwest."]) );
  SetSmell( ([
          "default" : "A foul smelling air flows up out of the depths."]) );
  SetTouch( ([
          "default" : "The darkness is so thick, it is almost touchable."]) );
  SetInventory( ([
          U_NPC + "dwarf_lieutenant" : 1,
          ]) );
 }
